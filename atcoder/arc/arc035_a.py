s = input()
s_i = s[::-1]
for i in range(len(s)):
    if s[i] == '*' or s_i[i] == '*' or s[i] == s_i[i]:
        continue
    else:
        print('NO')
        quit()
print('YES')
