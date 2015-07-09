s = input().split()
i = 0
ans = []
while i < len(s):
    cnt = 0
    try:
        while s[i+cnt] == 'not':
            cnt += 1
        if cnt % 2 == 1:
            ans.append('not')
        ans.append(s[i+cnt])
        i += cnt + 1
    except:
        ans += s[i:]
        i += cnt
print(' '.join(ans))
