from math import sqrt

while True:
    e = int(input())
    if e == 0: break
    ans = e
    for z in range(e):
        if z ** 3 > e: break
        y = int(sqrt(e - z ** 3))
        x = e - (z ** 3 + y ** 2)
        ans = min(ans, x + y + z)
    print(ans)
