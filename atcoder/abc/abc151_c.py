N, M = map(int, input().split())
penas = [0] * N
acs, pena = set(), 0
for _ in range(M):
    p, stat = input().split()
    p = int(p) - 1
    if stat == "AC" and p not in acs:
        acs.add(p)
        pena += penas[p]
    else:
        penas[p] += 1
print(len(acs), pena)
