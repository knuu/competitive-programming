N, A, B = map(int, input().split())
S = [int(input()) for _ in range(N)]
diff = max(S) - min(S)

if not diff:
    print(-1)
else:
    P = B / diff
    Q = (diff * A * N - B * sum(S)) / (diff * N)
    print(P, Q)
