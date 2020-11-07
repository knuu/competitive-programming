N = int(input())
start, end, both = dict(), dict(), dict()
for i in range(1, N+1):
    i_s = str(i)
    l, r = int(i_s[0]), int(i_s[-1])
    both[l, r] = both.get((l, r), 0) + 1

ans = 0
for i in range(1, N + 1):
    i_s = str(i)
    l, r = int(i_s[0]), int(i_s[-1])
    ans += both.get((r, l), 0)
print(ans)
