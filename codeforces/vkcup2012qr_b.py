n = int(input())
s = {1:0, 2:0, 3:0, 4:0}
for i in map(int, input().split()): s[i] += 1
ans = 0
ans += s[4]
ans += s[3]
s[1] = max(0, s[1]-s[3])
ans += (s[2] // 2)
if s[2] % 2:
    ans += 1
    s[1] = max(0, s[1] - 2)
ans += (s[1] // 4)
if s[1] % 4: ans += 1
print(ans)
    
