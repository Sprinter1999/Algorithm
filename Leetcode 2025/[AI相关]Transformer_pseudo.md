# Self-Attention (带 causal mask)
def self_attention(X):
    # 输入: X (batch_size, seq_len, d_model)
    # 线性变换得到Q/K/V
    Q = linear(X, W_q, b_q)  # (batch_size, seq_len, d_k)
    K = linear(X, W_k, b_k)
    V = linear(X, W_v, b_v)
    
    # 计算缩放点积注意力
    scores = matmul(Q, K.transpose(-2, -1)) / sqrt(d_k)
    if mask is not None:  # 解码器的mask（如因果掩码）
        scores = scores.masked_fill(mask == 0, -1e9)
    attn_weights = softmax(scores, dim=-1)
    attn_weights = dropout(attn_weights)
    
    # 加权求和
    output = matmul(attn_weights, V)  # (batch_size, seq_len, d_v)
    return output

# Cross-Attention (以encoder输出为上下文)
def cross_attention(decoder_X, encoder_output):
    # 输入: decoder_X (batch_size, tgt_seq_len, d_model)
    # encoder_output (batch_size, src_seq_len, d_model)
    Q = linear(decoder_X, W_q, b_q)  # Query来自解码器
    K = linear(encoder_output, W_k, b_k)  # Key来自编码器
    V = linear(encoder_output, W_v, b_v)
    
    # 后续计算与Self Attention相同
    scores = matmul(Q, K.transpose(-2, -1)) / sqrt(d_k)
    attn_weights = softmax(scores, dim=-1)
    attn_weights = dropout(attn_weights)
    output = matmul(attn_weights, V)
    return output

# FFN
def ffn(X):
    # 输入: X (batch_size, seq_len, d_model)
    output = linear(X, W1, b1)  # 扩展维度，例如d_model → 4*d_model
    output = relu(output)       # 或GELU
    output = dropout(output)
    output = linear(output, W2, b2)  # 恢复维度，4*d_model → d_model
    return output