def cut(d, w, s):
    s %= d + w
    if 0 < s < w:
        p1, p2 = (d, s), (d, w - s)
    else:
        s -= w
        p1, p2 = (s, w), (d - s, w)
    if p1[0] * p1[1] > p2[0] * p2[1]:
        p1, p2 = p2, p1
    return [p1, p2]


while True:
    N, W, D = map(int, input().split())
    if not (N | W | D):
        break
    square = [(D, W)]
    for _ in range(N):
        p, s = map(int, input().split())
        d, w = square.pop(p - 1)
        square.extend(cut(d, w, s))
    print(*sorted(d * w for d, w in square))
