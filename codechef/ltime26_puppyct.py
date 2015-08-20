for _ in range(int(input())):
    N, K = map(int, input().split())
    plus, minus = set(), set()
    for _ in range(K):
        x, y = map(lambda x: int(x)-1, input().split())
        plus.add(x+y)
        minus.add(x-y)
    ans = 0
    print(plus)
    print(minus)
    ans = sum(N - abs(N-p-1) for p in plus) + sum(N - abs(m) for m in minus)
    print(sum(N - abs(N-p-1) for p in plus), sum(N - abs(m) for m in minus))
    overlap = 0
    for p in plus:
        for m in minus:
             if p&1==m&1 and 0 <= p+m <= (N-1)*(N-1):
                 overlap += 1
    print(overlap)
    print(N * N - ans + overlap)
