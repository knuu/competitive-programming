s = input()
i = 0
cnt = 0
ans = 0
while i < len(s):
    if s[i:i+2] == '25':
        cnt += 1
        i += 1
    elif cnt > 0:
        ans += (cnt * (cnt+1) // 2)
        cnt = 0
    i += 1
ans += (cnt * (cnt+1) // 2)
print(ans)
       
