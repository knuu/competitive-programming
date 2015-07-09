ans = 0
for i in range(int(input())):
    s = list(map(int, input().split()))
    ans = max(ans, sum(s)-s[4]+s[4]*110/900)
print(ans)
