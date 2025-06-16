import torch
import torch.nn as nn
import torch.nn.functional as F

class PositionalEncoding(nn.Module):
    def __init__(self, d_model, max_len=5000):
        super().__init__()
        pe = torch.zeros(max_len, d_model)
        position = torch.arange(0, max_len, dtype=torch.float).unsqueeze(1)
        div_term = torch.exp(torch.arange(0, d_model, 2).float() * (-torch.log(torch.tensor(10000.0)) / d_model))
        pe[:, 0::2] = torch.sin(position * div_term)
        pe[:, 1::2] = torch.cos(position * div_term)
        self.register_buffer('pe', pe.unsqueeze(0))
        
    def forward(self, x):
        return x + self.pe[:, :x.size(1)]

class MultiHeadAttention(nn.Module):
    def __init__(self, d_model, num_heads):
        super().__init__()
        self.d_model = d_model
        self.num_heads = num_heads
        self.head_dim = d_model // num_heads
        
        self.qkv_proj = nn.Linear(d_model, 3 * d_model)
        self.out_proj = nn.Linear(d_model, d_model)
        
    def forward(self, x, mask=None, encoder_output=None):
        batch_size, seq_len, _ = x.size()
        
        # 自注意力使用x生成QKV
        # 交叉注意力使用encoder_output生成K和V
        if encoder_output is None:
            qkv = self.qkv_proj(x)
            q, k, v = qkv.chunk(3, dim=-1)
        else:
            q = self.qkv_proj(x)[:, :, :self.d_model]  # Q from decoder input
            kv = self.qkv_proj(encoder_output)[:, :, self.d_model:]  # KV from encoder
            k, v = kv.chunk(2, dim=-1)
        
        # 重塑为多头形式
        q = q.view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)
        k = k.view(batch_size, k.size(1), self.num_heads, self.head_dim).transpose(1, 2)
        v = v.view(batch_size, v.size(1), self.num_heads, self.head_dim).transpose(1, 2)
        
        # 计算注意力分数
        scores = torch.matmul(q, k.transpose(-2, -1)) / (self.head_dim ** 0.5)
        
        # 应用掩码（如果提供）
        if mask is not None:
            scores = scores.masked_fill(mask.unsqueeze(1) == 0, -1e9)
        
        attn = F.softmax(scores, dim=-1)
        context = torch.matmul(attn, v)
        context = context.transpose(1, 2).contiguous().view(batch_size, seq_len, self.d_model)
        output = self.out_proj(context)
        return output

class EncoderBlock(nn.Module):
    def __init__(self, d_model, num_heads, dropout=0.1):
        super().__init__()
        self.self_attn = MultiHeadAttention(d_model, num_heads)
        self.norm1 = nn.LayerNorm(d_model)
        self.dropout1 = nn.Dropout(dropout)
        
        self.ffn = nn.Sequential(
            nn.Linear(d_model, 4 * d_model),
            nn.GELU(),
            nn.Linear(4 * d_model, d_model),
            nn.Dropout(dropout)
        )
        self.norm2 = nn.LayerNorm(d_model)
        
    def forward(self, x, mask=None):
        attn_output = self.self_attn(x, mask)
        x = self.norm1(x + self.dropout1(attn_output))
        
        ffn_output = self.ffn(x)
        x = self.norm2(x + ffn_output)
        return x

class DecoderBlock(nn.Module):
    def __init__(self, d_model, num_heads, dropout=0.1):
        super().__init__()
        # 自注意力层（处理解码器输入）
        self.self_attn = MultiHeadAttention(d_model, num_heads)
        self.norm1 = nn.LayerNorm(d_model)
        self.dropout1 = nn.Dropout(dropout)
        
        # 交叉注意力层（处理编码器输出）
        self.cross_attn = MultiHeadAttention(d_model, num_heads)
        self.norm2 = nn.LayerNorm(d_model)
        self.dropout2 = nn.Dropout(dropout)
        
        self.ffn = nn.Sequential(
            nn.Linear(d_model, 4 * d_model),
            nn.GELU(),
            nn.Linear(4 * d_model, d_model),
            nn.Dropout(dropout)
        )
        self.norm3 = nn.LayerNorm(d_model)
        
    def forward(self, x, encoder_output, src_mask=None, tgt_mask=None):
        # 自注意力子层
        attn_output1 = self.self_attn(x, tgt_mask)
        x = self.norm1(x + self.dropout1(attn_output1))
        
        # 交叉注意力子层
        attn_output2 = self.cross_attn(x, src_mask, encoder_output)
        x = self.norm2(x + self.dropout2(attn_output2))
        
        # 前馈网络子层
        ffn_output = self.ffn(x)
        x = self.norm3(x + ffn_output)
        return x

class TransformerEncoder(nn.Module):
    def __init__(self, num_layers, d_model, num_heads, dropout=0.1):
        super().__init__()
        self.layers = nn.ModuleList([
            EncoderBlock(d_model, num_heads, dropout)
            for _ in range(num_layers)
        ])
        
    def forward(self, x, mask=None):
        for layer in self.layers:
            x = layer(x, mask)
        return x

class TransformerDecoder(nn.Module):
    def __init__(self, num_layers, d_model, num_heads, dropout=0.1):
        super().__init__()
        self.layers = nn.ModuleList([
            DecoderBlock(d_model, num_heads, dropout)
            for _ in range(num_layers)
        ])
        
    def forward(self, x, encoder_output, src_mask=None, tgt_mask=None):
        for layer in self.layers:
            x = layer(x, encoder_output, src_mask, tgt_mask)
        return x

# 示例使用
def demo_transformer():
    # 模型参数
    d_model = 512
    num_heads = 8
    num_layers = 6
    
    # 创建模型
    encoder = TransformerEncoder(num_layers, d_model, num_heads)
    decoder = TransformerDecoder(num_layers, d_model, num_heads)
    pos_encoder = PositionalEncoding(d_model)
    pos_decoder = PositionalEncoding(d_model)
    
    # 模拟输入
    src = torch.randn(32, 10, d_model)  # 源序列 [batch, src_len, d_model]
    tgt = torch.randn(32, 15, d_model)  # 目标序列 [batch, tgt_len, d_model]
    
    # 添加位置编码
    src_with_pos = pos_encoder(src)
    tgt_with_pos = pos_decoder(tgt)
    
    # 创建掩码（示例：仅保留上三角部分为1，其余为0）
    tgt_mask = torch.tril(torch.ones(15, 15))
    
    # 编码和解码
    encoder_output = encoder(src_with_pos)
    decoder_output = decoder(tgt_with_pos, encoder_output, tgt_mask=tgt_mask)
    
    print(f"编码器输入形状: {src.shape}, 输出形状: {encoder_output.shape}")
    print(f"解码器输入形状: {tgt.shape}, 输出形状: {decoder_output.shape}")

if __name__ == "__main__":
    demo_transformer()