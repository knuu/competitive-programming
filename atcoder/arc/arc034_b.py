N = int(input())

ans = 0
ansx = []

for i in range(max(1, N-9*(len(str(N)))), N+1):
    if i + sum([int(x) for x in str(i)]) == N:
        ans += 1
        ansx.append(i)

print(ans)
for x in ansx: print(x)
