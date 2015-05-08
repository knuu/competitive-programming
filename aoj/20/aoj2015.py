while True:
    N, M = map(int, raw_input().split())
    if N == 0 and M == 0: break
    h = [input() for _ in range(N)]
    for i in range(N-1):
        h[i+1] += h[i]
    w = [input() for _ in range(M)]
    for i in range(M-1):
        w[i+1] += w[i]
    h = [0] + h
    w = [0] + w
    hl = [0] * (h[-1] + 1)
    wl = [0] * (w[-1] + 1)
    for i in range(N):
        for j in range(i+1, N+1):
            hl[h[j]-h[i]] += 1
    for i in range(M):
        for j in range(i+1, M+1):
            wl[w[j]-w[i]] += 1

    ans = 0
    for i, j in zip(hl, wl):
        ans += i*j
    print ans
    
