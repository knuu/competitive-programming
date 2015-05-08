P = [[25],[39],[51],[76],[163],[111],[136, 58],[128],[133],[138]]
#P = [[100], [120], [20, 90]]
ans = [0]
for p in P:
    if len(p) == 1:
        full = p[0]
        ans_c = ans[:]
        for a in ans:
            ans_c.append(a+full)
        ans = ans_c[:]
    elif len(p) == 2:
        full, part = p
        ans_c1 = ans[:]
        ans_c2 = ans[:]
        for a in ans:
            ans_c1.append(a+full)
        for a in ans:
            ans_c2.append(a+part)
        ans = ans_c1[:] + ans_c2[:]
print('\n'.join([str(x) for x in sorted(list(set(ans)))]))

