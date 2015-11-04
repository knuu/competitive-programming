import itertools
while True:
    N, K, S = map(int, input().split())
    if not N: break
    print(sum(sum(l) == S for l in itertools.combinations(range(1, N+1), K)))
