ps = [tuple(int(x) for x in input().split()) for _ in range(3)]
ps.sort()
xa, ya = ps[0]
xb, yb = ps[1]
xc, yc = ps[2]
if xa == xb:
    if xc == xa:
        print(1)
    elif yc <= ya or yb <= yc:
            print(2)
    else:
        print(3)
elif ya == yb:
    if yc == ya:
        print(1)
    else:
        print(2)
elif ya < yb:
    if xb == xc or yb == yc:
        print(2)
    else:
        print(3)
else:
    if yb == yc or (xb == xc and yc <= ya):
        print(2)
    else:
        print(3)
