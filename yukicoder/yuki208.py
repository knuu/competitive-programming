x, y = map(int, input().split())
x2, y2 = map(int, input().split())
if x == y and x2 == y2 and x2 < x:
    print(x+1)
else:
    print(min(x, y)+abs(x-y))
