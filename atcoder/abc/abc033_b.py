N = int(input())
towns = list()
p = 0
for i in range(N):
    S, P = input().split()
    towns.append((int(P), S))
    p += int(P)
towns.sort()
print(towns[-1][1] if towns[-1][0] * 2 > p else 'atcoder')
