a, b = map(int, input().split())
ans = 0
N = 0
for i in range(2, 61):
    N = (1 << i) - 1
    for j in range(N.bit_length() - 1):
        x = N - (1 << j)
        if a <= x <= b:
            ans += 1
print(ans)
            
    
