while True:
    N = int(input())
    if N == 0:
        break
    air = [input() for _ in range(N)]
    codes = [''.join(x for i, x in enumerate(s) if i == 0 or s[i-1] in 'aiueo') for s in air]
    max_len = max(len(x) for x in codes)
    for k in range(1, max_len + 1):
        if len(set(x[:k] for x in codes)) == N:
            print(k)
            break
    else:
        print(-1)
