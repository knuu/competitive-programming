from math import sqrt
x0, y0, vx, vy, vh = map(int, input().split())
a = vx**2 + vy**2 - vh**2
b = vx * x0 + vy * y0
c = x0**2 + y0**2
if a == 0:
    if b == 0:
        if (x0, y0) == (0, 0):
            print(0)
        else:
            print("IMPOSSIBLE")
    else:
        t = - c / (2. * b)
        if t >= 0:
            print('{:.20f}'.format(t))
        else:
            print("IMPOSSIBLE")
elif b**2 - a*c < 0:
    print("IMPOSSIBLE")
else:
    t1 = (-b + sqrt(b**2 - a*c)) / a
    t2 = (-b - sqrt(b**2 - a*c)) / a
    if t1 >= 0 and t2 >= 0:
        print('{:.20f}'.format(min(t1, t2)))
    elif t1 >= 0:
        print('{:.20f}'.format(t1))
    elif t2 >= 0:
        print('{:.20f}'.format(t2))
    else:
        print("IMPOSSIBLE")
