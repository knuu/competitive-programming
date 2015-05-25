A, B, C, K = map(int, input().split())
S, T = map(int, input().split())
if S + T >= K:
    print(A * S + B * T - C * (S + T))
else:
    print(A * S + B * T)
