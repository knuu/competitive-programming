n, m, l = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]
B = [list(map(int, input().split())) for _ in range(m)]

for i in range(n):
    t = [str(sum([A[i][k] * B[k][j] for k in range(m)])) for j in range(l)]
    print(" ".join(t))




        
