def read_list(t): return [t(x) for x in input().split()]
def read_line(t): return t(input())
def read_lines(t, N): return [t(input()) for _ in range(N)]

N = read_line(int)
s1, s2 = read_line(str), read_line(str)
for i in range(N):
    if s1[i].isdigit():
        s1, s2 = s1.replace(s2[i], s1[i]), s2.replace(s2[i], s1[i])
    elif s2[i].isdigit():
        s1, s2 = s1.replace(s1[i], s2[i]), s2.replace(s1[i], s2[i])
    elif s1[i] != s2[i]:
        s1, s2 = s1.replace(s2[i], s1[i]), s2.replace(s2[i], s1[i])

ans = 1
for i in set(list(s1+s2)):
    if i.isupper():
        if i == s1[0] or i == s2[0]:
            ans *= 9
        else:
            ans *= 10
print(ans)
