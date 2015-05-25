N, D, K = map(int, input().split())
cango = [list(map(lambda x:int(x)-1, input().split())) for _ in range(D)]
dest = [list(map(lambda x:int(x)-1, input().split())) for _ in range(K)]
races = [(-1, -1) for _ in range(K)]

ans = [-1 for _ in range(K)]

for i, (L, R) in enumerate(cango):
    for c, (s, t) in enumerate(races):
        if (s, t) == (-1, -1) and L <= dest[c][0] <= R:
            races[c] = (L, R)
        elif (s, t) != (-1, -1) and (L <= s <= R or L <= t <= R):
            races[c] = (min(s, L), max(t, R))
        if ans[c] == -1 and races[c][0] <= dest[c][1] <= races[c][1]:
            ans[c] = i+1

print(*ans, sep='\n')
