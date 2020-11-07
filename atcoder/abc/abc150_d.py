import sys
if sys.version_info.major >= 3 and sys.version_info.minor >= 5:
    from math import gcd
else:
    from fractions import gcd


N, M = map(int, input().split())
A = sorted(set(int(x) for x in input().split()))
if any(a % 2 > 0 for a in A):
    print(0)
    quit()
div_2 = []
for a in A:
    cnt = 0
    while a % 2 == 0:
        a //= 2
        cnt += 1
    div_2.append(cnt)
if len(set(div_2)) > 1:
    print(0)
    quit()

g = A[0]
for a in A:
    g = gcd(g, a)
lcm = 1
too_big = False

for a in A:
    if not too_big:
        lcm = lcm * a // gcd(lcm, a)
        if lcm > M * 2:
            too_big = True

if too_big:
    print(0)
elif lcm > M:
    print(1)
else:
    K = M // lcm
    ans = K + 1
    if lcm * K + lcm // 2 > M:
        ans -= 1
    print(ans)
