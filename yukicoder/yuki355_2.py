def is_finish(x, y):
    return x == 4
l = list(range(4))
a = set(range(10))
print(*l)
X, Y = map(int, input().split())
if is_finish(X, Y):
    exit(0)
for i in range(4):
    not_in = a - set(l)
    ng = []
    for n in not_in:
        tmpl = l[:]
        tmpl[i] = n
        print(*tmpl)
        tmpx, tmpy = map(int, input().split())
        if is_finish(tmpx, tmpy):
            exit(0)
        if tmpx <= X and tmpy <= Y:
            ng.append(n)
        if tmpx > X:
            l = tmpl[:]
            X, Y = tmpx, tmpy
            break
        elif tmpx < X:
            break
    else:
        for j in range(i+1, 4):
            tmpl = l[:]
            tmpl[i], tmpl[j] = tmpl[j], ng[0]
            print(*tmpl)
            tmpx, tmpy = map(int, input().split())
            if is_finish(tmpx, tmpy):
                exit(0)
            if tmpx > X:
                l = tmpl[:]
                X, Y = tmpx, tmpy
                break
        else:
            assert(0)
assert(0)
