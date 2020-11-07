S = input()
N = len(S)
non_x = []
s_notx = []
for i, s in enumerate(S):
    if s != 'x':
        non_x.append(i)
        s_notx.append(s)
s_notx = ''.join(s_notx)
if s_notx != s_notx[::-1]:
    print(-1)
    quit()
if not non_x:
    print(0)
    quit()
ans = 0
L = len(non_x)
if L % 2 == 0:
    left, right = L // 2 - 1, L // 2
else:
    left = right = L // 2
left, right = left - 1, right + 1
for i in range(left + 1):
    l, r = left - i, right + i
    ans += abs((non_x[l + 1] - non_x[l]) - (non_x[r] - non_x[r - 1]))
ans += abs(non_x[0] - (N - non_x[-1] - 1))
print(ans)
