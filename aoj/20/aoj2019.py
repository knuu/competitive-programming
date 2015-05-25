while True:
    N, M = map(int, input().split())
    if N == 0 and M == 0: break
    travel = [list(map(int, input().split())) for _ in range(N)]
    travel.sort(reverse=True, key=lambda x:x[1])
    for i, (d, _) in enumerate(travel):
        if M == 0: break
        travel[i][0] = max(0, d-M)
        M = max(0, M-d)
    print(sum(d*p for d, p in travel))
