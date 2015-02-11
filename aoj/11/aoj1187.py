while True:
    M, T, P, R = map(int, input().split())
    if M == 0: break
    teams = [[0, 0, i+1] for i in range(T)]
    miss = [[0 for _ in range(P)] for _ in range(T)]
    solved, time = 0, 1
    logs = [map(int, input().split()) for _ in range(R)]
    for m, t, p, r in logs:
        t -= 1
        p -= 1
        if r == 0:
            teams[t][solved] += 1
            teams[t][time] -= (m + miss[t][p] * 20)
        else:
            miss[t][p] += 1
    teams = sorted(teams, reverse=True)
    before_s, before_t = 0, 0
    for i in range(T):
        s, t, n = teams[i]
        if i != 0:
            print('=' if (s == before_s and t == before_t) else ',', end='')
        before_s, before_t = s, t
        print(n, end='')
    print('')
