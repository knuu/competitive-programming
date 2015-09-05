N, K = map(int, input().split())
print((1+ (K-1)*3 + (N-K)*3 + (K-1) * (N-K) * 6) / (N**3))
