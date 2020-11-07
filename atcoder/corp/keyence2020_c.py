N, K, S = map(int, input().split())
if S == 1:
    const = S + 1
else:
    const = S - 1
ans = []
for i in range(N):
    if i < K:
        ans.append(S)
    else:
        ans.append(const)
print(*ans)
