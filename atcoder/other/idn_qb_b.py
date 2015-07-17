s = input()
t = input()
for i in range(len(s)):
    if s == t:
        print(i)
        break
    else:
        s = s[-1] + s[:-1]
else:
    print(-1)
