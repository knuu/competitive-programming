import itertools
K, N = map(int, input().split())

words = [[[int(x)-1 for x in v], w] for v, w in [input().split() for _ in range(N)]]

for l in itertools.product([1, 2, 3], repeat=K):
    ans = [[] for _ in range(K)]
    for v, w in words:
        if sum(l[i] for i in v) != len(w):
            break
        s = 0
        for i in v:
            ans[i].append(w[s:s+l[i]])
            s += l[i]
    else:
        if all(len(set(a)) == 1 for a in ans):
            print(*[a[0] for a in ans], sep='\n')
            exit(0)
