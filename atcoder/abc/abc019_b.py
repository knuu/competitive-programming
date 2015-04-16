s = input()
ans = ''
cnt = 1
for i in range(1,len(s)):
    if s[i-1] == s[i]:
        cnt += 1
    else:
        ans += s[i-1] + str(cnt)
        cnt = 1
ans += s[-1] + str(cnt)
print(ans)
