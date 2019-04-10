N, K, M, R = map(int, input().split())
S = sorted([int(input()) for _ in range(N-1)], reverse=True)
if sum(S[:K]) >= K * R:
    print(0)
elif sum(S[:K-1]) + M < K * R:
    print(-1)
else:
    print(K * R - sum(S[:K-1]))
