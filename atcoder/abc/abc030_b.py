N, M = map(int, input().split())
N %= 12
l = M / 60
s = (N + l) / 12
ans = 360 * abs(l - s)
print('{:.12}'.format(min(ans, 360 - ans)))
