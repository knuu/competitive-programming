while True:
    t, p, r = map(int, input().split())
    if t == 0 and p == 0 and r == 0: break
    logs = [input().split() for _ in range(r)]
    score = [[0, 0, -i, [0] * p] for i in range(t)]
    c_n, pen, w_n = 0, 1, 3
    for tid, pid, time, msg in logs:
        tid, pid, time = int(tid) - 1, int(pid) - 1, int(time)
        if msg == 'WRONG':
            score[tid][w_n][pid] += 1
        elif msg == 'CORRECT':
            score[tid][c_n] += 1
            score[tid][pen] -= (score[tid][w_n][pid] * 1200 + time)
            score[tid][w_n][pid] = 0
    score = sorted(score, reverse=True)
    for c_n, pen, t, _ in score:
        print(abs(t) + 1 , c_n, abs(pen))
