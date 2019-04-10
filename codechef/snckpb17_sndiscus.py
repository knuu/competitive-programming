import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input
for _ in range(int(input())):
    N = int(input())
    points = [[int(x) for x in input().split()] for _ in range(N)]
    ans = int(1e9)
    for x in range(1, 51):
        for y in range(1, 51):
            cand = 0
            for x1, y1, x2, y2 in points:
                if x1 == x2:
                    if min(y1, y2) <= y <= max(y1, y2):
                        cand = max(cand, abs(x - x1))
                    else:
                        cand = max(cand, abs(x - x1) + min(abs(y1 - y), abs(y2 - y)))
                else:
                    if min(x1, x2) <= x <= max(x1, x2):
                        cand = max(cand, abs(y - y1))
                    else:
                        cand = max(cand, abs(y - y1) + min(abs(x1 - x), abs(x2 - x)))
            ans = min(ans, cand)
    print(ans)
