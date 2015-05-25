N = int(input())
trees = [list(map(int, input().split())) for _ in range(N)]

ans = 2 if N >= 2 else 1
for i in range(1, N-1):
    x, h = trees[i]
    px, ph = trees[i-1]
    nx, nh = trees[i+1]
    if px < x - h:
        ans += 1
    elif x + h < nx:
        trees[i][0] = x + h
        ans += 1
print(ans)
        
    
