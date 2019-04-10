X, Y = map(int, input().split())
ans = 1
while X * 2 <= Y:
    X *= 2
    ans += 1
print(ans)
