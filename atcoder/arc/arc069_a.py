N, M = map(int, input().split())
ans = min(N, M // 2)
N, M = N - ans, M - ans * 2
ans += M // 4
print(ans)
