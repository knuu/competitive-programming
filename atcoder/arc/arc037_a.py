n = int(input())
M = list(map(int, input().split()))
ans = 0
for m in M:
    if m < 80: ans += 80 - m
print(ans)
