# Encoder 伪代码（PyTorch风格）
class EncoderLayer(nn.Module):
    def __init__(self, d_model, n_heads, ffn_hidden, dropout):
        super().__init__()
        self.self_attn = MultiHeadAttention(d_model, n_heads)  # 多头自注意力
        self.norm1 = nn.LayerNorm(d_model)
        self.dropout1 = nn.Dropout(dropout)
        
        self.ffn = FeedForward(d_model, ffn_hidden)           # 前馈网络
        self.norm2 = nn.LayerNorm(d_model)
        self.dropout2 = nn.Dropout(dropout)

    def forward(self, x, mask):
        # 自注意力 + 残差
        attn_out = self.self_attn(q=x, k=x, v=x, mask=mask)
        x = self.norm1(x + self.dropout1(attn_out))
        
        # 前馈网络 + 残差
        ffn_out = self.ffn(x)
        x = self.norm2(x + self.dropout2(ffn_out))
        return x

class Encoder(nn.Module):
    def __init__(self, vocab_size, max_len, d_model, n_layers, n_heads, ffn_hidden, dropout):
        super().__init__()
        self.embed = nn.Embedding(vocab_size, d_model)
        self.pos_enc = PositionalEncoding(d_model, max_len)
        self.layers = nn.ModuleList([EncoderLayer(d_model, n_heads, ffn_hidden, dropout) 
                                    for _ in range(n_layers)])

    def forward(self, src, src_mask):
        x = self.embed(src) + self.pos_enc(src)  # 输入嵌入 + 位置编码
        for layer in self.layers:
            x = layer(x, src_mask)               # 堆叠N个编码层
        return x                                 # 输出形状: [batch_size, seq_len, d_model]

# Decoder 伪代码（PyTorch风格）
class DecoderLayer(nn.Module):
    def __init__(self, d_model, n_heads, ffn_hidden, dropout):
        super().__init__()
        self.masked_attn = MultiHeadAttention(d_model, n_heads)  # 掩码自注意力
        self.norm1 = nn.LayerNorm(d_model)
        self.dropout1 = nn.Dropout(dropout)
        
        self.cross_attn = MultiHeadAttention(d_model, n_heads)  # 交叉注意力
        self.norm2 = nn.LayerNorm(d_model)
        self.dropout2 = nn.Dropout(dropout)
        
        self.ffn = FeedForward(d_model, ffn_hidden)             # 前馈网络
        self.norm3 = nn.LayerNorm(d_model)
        self.dropout3 = nn.Dropout(dropout)

    def forward(self, x, enc_out, src_mask, tgt_mask):
        # 掩码自注意力 + 残差
        attn_out = self.masked_attn(q=x, k=x, v=x, mask=tgt_mask)
        x = self.norm1(x + self.dropout1(attn_out))
        
        # 交叉注意力（Q来自解码器，K/V来自编码器） + 残差
        cross_out = self.cross_attn(q=x, k=enc_out, v=enc_out, mask=src_mask)
        x = self.norm2(x + self.dropout2(cross_out))
        
        # 前馈网络 + 残差
        ffn_out = self.ffn(x)
        x = self.norm3(x + self.dropout3(ffn_out))
        return x

class Decoder(nn.Module):
    def __init__(self, vocab_size, max_len, d_model, n_layers, n_heads, ffn_hidden, dropout):
        super().__init__()
        self.embed = nn.Embedding(vocab_size, d_model)
        self.pos_enc = PositionalEncoding(d_model, max_len)
        self.layers = nn.ModuleList([DecoderLayer(d_model, n_heads, ffn_hidden, dropout)
                                    for _ in range(n_layers)])

    def forward(self, tgt, enc_out, src_mask, tgt_mask):
        x = self.embed(tgt) + self.pos_enc(tgt)  # 目标嵌入 + 位置编码
        for layer in self.layers:
            x = layer(x, enc_out, src_mask, tgt_mask)  # 堆叠N个解码层
        return x                                   # 输出形状: [batch_size, seq_len, d_model]

# 关键组件说明
class MultiHeadAttention(nn.Module): ...     # 实现Q/K/V拆分和注意力计算
class FeedForward(nn.Module): ...            # 两个线性层+激活函数（如ReLU）
class PositionalEncoding(nn.Module): ...     # 生成正弦/余弦位置编码