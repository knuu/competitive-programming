aI, aO, aT, aJ, aL, aS, aZ = map(int, input().split())
ans = aO
p = [aI, aJ, aL]
for i in range(3):
    if p[i] >= 2:
        if p[i] % 2 == 0:
            ans += (p[i] - 2) // 2 * 2
            p[i] = 2
        else:
            ans += p[i] // 2 * 2
            p[i] = 1
p.sort()
if sum(p) >= 5:
    ans += sum(p) // 2 * 2
elif sum(p) == 4:
    if p == [1, 1, 2]:
        ans += 3
    elif p == [0, 2, 2]:
        ans += 4
    else:
        assert(False)
elif sum(p) == 3:
    if p == [0, 1, 2]:
        ans += 2
    elif p == [1, 1, 1]:
        ans += 3
    else:
        assert(False)
elif sum(p) == 2:
    if p == [0, 0, 2]:
        ans += 2
    elif p == [0, 1, 1]:
        pass
    else:
        assert(False)
else:
    assert(sum(p) <= 1)
print(ans)
