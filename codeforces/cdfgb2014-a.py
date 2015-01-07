n, t = map(int, input().split())
t = t - 1
j = [int(x) for x in input().split()]

cur = 0
while True:
    if cur > t:
        print('NO')
        break
    cur += j[cur]
    if cur == t:
        print('YES')
        break
