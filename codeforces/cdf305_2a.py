s = input()
k = int(input())
if len(s) % k != 0:
    print('NO')
    exit(0)
lenS = len(s)
for i in range(0, len(s), lenS//k):
    if s[i:i+lenS//k] != s[i:i+lenS//k][::-1]:
        print('NO')
        break
else:
    print('YES')
