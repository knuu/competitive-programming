N, S, T = map(int, input().split())
W = int(input())
A = [int(input()) for _ in range(N-1)]
ans = 1 if S <= W <= T else 0
for a in A:
    W += a
    if S <= W <= T:
        ans += 1
print(ans)
