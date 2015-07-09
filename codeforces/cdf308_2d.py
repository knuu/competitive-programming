from fractions import gcd

N = input()
points = [map(int, raw_input().split()) for _ in xrange(N)]

ans = N * (N-1) * (N-2) // 6
lines = {}
for i in xrange(N-1):
    for j in range(i+1, N):
        x1, y1 = points[i]
        x2, y2 = points[j]
        g = gcd(x1-x2, y1-y2)
        dx, dy = (x1-x2)//g, (y1-y2)//g
        a, b, c = dy, dx, dx * y1 - dy * x1
        lines[(a, b, c)] = lines.get((a, b, c), 0) + 1

for val in lines.values():
    if val != 1:
        n = (1 + int(pow(1+8*val, 0.5))) // 2
        ans -= n * (n-1) * (n-2) // 6

print(ans)
            
        
        
          
