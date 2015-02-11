from functools import reduce
while True:
    n = input()
    if n == '0000': break
    if len(n) < 4: n = n.zfill(4)
    if reduce(lambda x,y: x and y, [n[0] == s for s in n]):
        print('NA')
    else:
        cnt = 0
        while n != '6174':
            s = ''.join(sorted(n))
            l = s[::-1]
            n = str(int(l)-int(s))
            if len(n) < 4: n = n.zfill(4)
            cnt += 1
        print(cnt)
