N = int(input())
R = [int(x) for x in input().split()]
g = [R[0]]
i = 1
while i < N and g[0] == R[i]: i += 1
if i != N:
    g.append(R[i])
    i += 1
while i < N:
    if g[-2] < g[-1] < R[i] or g[-2] > g[-1] > R[i]:
        g[-1] = R[i]
    elif g[-2] < g[-1] > R[i] or g[-2] > g[-1] < R[i]:
        g.append(R[i])
    i += 1

G = len(g)
print(G if G >= 3 else 0)
