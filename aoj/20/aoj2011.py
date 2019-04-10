import itertools
while True:
    N = int(input())
    if not N:
        break
    D = [[] for _ in range(30)]
    for i in range(N):
        for x in map(int, input().split()[1:]):
            D[x - 1].append(i)
    C = [1 << i for i in range(N)]
    for d in range(30):
        for i, j in itertools.combinations(D[d], 2):
            C[i] = C[j] = C[i] | C[j]
        if any(x == (1 << N) - 1 for x in C):
            print(d + 1)
            break
    else:
        print(-1)
