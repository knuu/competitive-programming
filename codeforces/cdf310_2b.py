N = int(input())
G = [int(x) for x in input().split()]
trueG = list(range(N))
for i in range(N):
    for j in range(N):
        G[j] = (G[j] + (-1 if j % 2 else 1)) % N
    if G == trueG:
        print('Yes')
        break
else:
    print('No')
