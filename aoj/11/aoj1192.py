def calRate(m, r):
    return int(1.0 * m * (100.0 + r) / 100.0)

while True:
    x, y, s = map(int, raw_input().split())
    if x == 0 and y == 0 and s == 0: break
    ans = 0
    for i in range(1, s):
        ix = calRate(i, x)
        j = int((s - ix) * 100.0 / (100.0 + x))
        if j < 1 or j > s-1:
            continue
        while True:
            if calRate(i, x) + calRate(j, x) < s:
                j += 1
            else:
                break
        if calRate(i, x) + calRate(j, x) != s:
            continue
        ans = max(ans, calRate(i, y) + calRate(j, y))
        print(i, j)
    print ans
