def is_finish(x, y):
    return x == 4
l = list(range(4))
cnt = 0
a = set(range(10))
assert(len(a & set(l)) == 4)
print(*l)
cnt += 1
X, Y = map(int, input().split())
if is_finish(X, Y):
    exit(0)

for i in range(4):
    not_in = a - set(l)
    for n in not_in:
        tmpl = l[:]
        tmpl[i] = n
        assert(len(a & set(tmpl)) == 4)
        print(*tmpl)
        cnt += 1
        assert(cnt <= 100)
        tmpx, tmpy = map(int, input().split())
        if is_finish(tmpx, tmpy):
            exit(0)
        if tmpx > X:
            l = tmpl[:]
            X, Y = tmpx, tmpy
            break
        elif tmpx < X:
            break
    else:
        for j in range(i+1, 4):
            tmpl = l[:]
            tmpl[i], tmpl[j] = tmpl[j], tmpl[i]
            assert(len(a & set(tmpl)) == 4)
            print(*tmpl)
            cnt += 1
            assert(cnt <= 100)

            tmpx, tmpy = map(int, input().split())
            if is_finish(tmpx, tmpy):
                exit(0)
            if tmpx > X:
                l = tmpl[:]
                X, Y = tmpx, tmpy
                break
        else:
            assert(0)
