N = int(input())
P = [int(x) - 1 for x in input().split()]
now = 0
ans = 0
while now < N:
    if P[now] == now:
        start = now
        while now < N and P[now] == now:
            now += 1
        ans += (now - start) // 2 + (now - start) % 2
    else:
        now += 1
print(ans)
