s = input()
lenS = len(s)
i = 0
t = s[:]
if 'AB' in t:
    i = t.index('AB')
    t = t[:i] + 'CC' + t[i+2:]
    if 'BA' in t:
        print('YES')
        exit(0)
t = s[:]
if 'BA' in t:
    i = t.index('BA')
    t = t[:i] + 'CC' + t[i+2:]
    if 'AB' in t:
        print('YES')
        exit(0)
print('NO')
