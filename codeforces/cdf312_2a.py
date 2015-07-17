N = int(input())
plus = []
minus = []
for i in range(N):
    pos, x = map(int, input().split())
    if pos > 0:
        plus.append((-pos, x))
    else:
        minus.append((pos, x))

plus.sort()
minus.sort()
d = True if len(plus) > len(minus) else False
ans = 0
while True:
    if d:
        if not plus: break
        _, x = plus.pop()
        ans += x
        d = False
    else:
        if not minus: break
        _, x = minus.pop()
        ans += x
        d = True
print(ans)
    
