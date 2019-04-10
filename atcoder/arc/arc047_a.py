N, L = map(int, input().split())
now, ans = 1, 0
for ope in input():
    if ope == '+':
        now += 1
        if now > L:
            now = 1
            ans += 1
    else:
        now -= 1
print(ans)
