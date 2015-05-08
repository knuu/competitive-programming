N = int(input())
P = [list(map(int, input().split())) for _ in range(N)]
x0, y0 = P[0]
ans = y0 - x0
for x, y in P:
    if y - x <= 0:
        print(-1)
        exit(0)
    elif ans != y - x:
        print(-1)
        exit(0)
print(ans)
        
        
