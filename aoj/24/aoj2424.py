q = int(input())
num = [int(input()) for _ in range(q)]
for n in num:
    cnt = 0
    mulnum = [n]
    while True:
        strn = str(n)
        if len(strn) == 1:
            break
        m = 0
        for i in range(len(strn) - 1):
            m = max(m, int(strn[:i+1]) * int(strn[i+1:]))
        if m in mulnum:
            cnt = -1
            break
        else:
            cnt += 1
            mulnum.append(m)
            n = m
    print(cnt)
