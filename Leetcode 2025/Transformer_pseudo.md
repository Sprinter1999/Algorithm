# Self-Attention (带 causal mask)
def self_attention(x):
    # 输入x: [batch, seq_len, dim]
    Q = x @ Wq  # [b, s, d_k]
    K = x @ Wk  # [b, s, d_k]
    V = x @ Wv  # [b, s, d_v]
    
    attn = Q @ K.transpose(-1,-2) / sqrt(d_k)  # [b, s, s]
    mask = tril(matrix of ones)  # 下三角遮蔽矩阵
    attn = attn.masked_fill(mask == 0, -inf)  # 阻止未来信息
    attn = softmax(attn, dim=-1)
    attn = dropout(attn)
    return attn @ V  # [b, s, d_v]

# Cross-Attention (以encoder输出为上下文)
def cross_attention(x, encoder_out):
    # x: [b, s, dim] (decoder输入)
    # encoder_out: [b, s_enc, dim] (encoder输出)
    Q = x @ Wq  # [b, s, d_k]
    K = encoder_out @ Wk  # 来自encoder
    V = encoder_out @ Wv  # 来自encoder
    
    attn = Q @ K.transpose(-1,-2) / sqrt(d_k)  # [b, s, s_enc]
    attn = softmax(attn, dim=-1)
    attn = dropout(attn)
    return attn @ V  # [b, s, d_v]