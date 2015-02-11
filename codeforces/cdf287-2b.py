r, x, y, n_x, n_y = map(int, input().split())
d = 2 * r
dis = (x - n_x) ** 2 + (y - n_y) ** 2
ans = pow(dis / (d ** 2), 0.5)
if ans ** 2 == int(ans) ** 2 + 0.0:
    print(int(ans))
else:
    print(int(ans)+1)
