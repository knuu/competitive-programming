import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input
for t in range(int(input())):
    C, J = input().split()
    if '?' in C:
        incl, cond_c = [C], []
    else:
        incl, cond_c = [], [C]

    while incl:
        s = incl.pop()
        idx = s.index('?')
        if s.count('?') == 1:
            for i in range(10):
                cond_c.append(''.join(s[:idx] + str(i) + s[idx+1:]))
        else:
            for i in range(10):
                incl.append(''.join(s[:idx] + str(i) + s[idx+1:]))
    if '?' in J:
        incl, cond_j = [J], []
    else:
        incl, cond_j = [], [J]
    while incl:
        s = incl.pop()
        idx = s.index('?')
        if s.count('?') == 1:
            for i in range(10):
                cond_j.append(''.join(s[:idx] + str(i) + s[idx+1:]))
        else:
            for i in range(10):
                incl.append(''.join(s[:idx] + str(i) + s[idx+1:]))
    ans, diff = [], 0
    for c in cond_c:
        for j in cond_j:
            d = abs(int(c) - int(j))
            if not ans or d < diff or d == diff and [j, c] < ans:
                ans = [j, c]
                diff = d
    print("Case #{}: {} {}".format(t+1, ans[1], ans[0]))
