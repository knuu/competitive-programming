while True:
    N, M = map(int, input().split())
    if N == 0 and M == 0: break
    r = int(input())
    students = [{'start': [], 'end': [], 'login': []} for _ in range(M)]
    for _ in range(r):
        t, n, m, s = map(int, input().split())
        n -= 1; m -= 1
        if s == 1:
            if len(students[m]['login']) == 0:
                students[m]['start'].append(t)
            students[m]['login'].append(n)
        elif s == 0:
            students[m]['login'].remove(n)
            if len(students[m]['login']) == 0:
                students[m]['end'].append(t)
    q = int(input())
    for _ in range(q):
        ts, te, m = map(int, input().split())
        m -= 1
        ans = 0
        for s, e in zip(students[m]['start'], students[m]['end']):
            if s <= ts < te <= e:
                ans = te - ts
                break
            elif s <= ts <= e < te:
                ans += e - ts
            elif ts < s <= te <= e:
                ans += te - s
            elif ts < s < e < te:
                ans += e - s
        print(ans)
