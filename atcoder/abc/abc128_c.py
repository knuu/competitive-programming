N, M = map(int, input().split())
S = [[] for _ in range(N)]
for i in range(M):
    ss = list(map(int, input().split()))[1:]
    for s in ss:
        S[s - 1].append(i)
P = [int(x) for x in input().split()]
ans = 0
for bit in range(1 << N):
    den = [0] * M
    for i in range(N):
        if bit >> i & 1:
            for s in S[i]:
                den[s] += 1
    if all(d % 2 == p for d, p in zip(den, P)):
        ans += 1
print(ans)
