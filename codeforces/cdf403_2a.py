N = int(input())
socks = [int(x) - 1 for x in input().split()]
now, ans = 0, 0
table = [0] * N
for sock in socks:
    if table[sock]:
        now -= 1
        table[sock] -= 1
    else:
        now += 1
        table[sock] += 1
    ans = max(ans, now)
print(ans)
