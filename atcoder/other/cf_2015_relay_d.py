hs, ms = map(int, input().split())
hn, mn = map(int, input().split())
start, now = hs * 60 + ms, hn * 60 + mn
if now <= start:
    print('Yes')
    exit(0)
for t in range(now, 12 * 60):
    h, m = (t // 60 + 6) % 12, (t % 60 + 30) % 60
    if h * 60 + m <= start:
        print('Yes')
        break
else:
    print('No')
