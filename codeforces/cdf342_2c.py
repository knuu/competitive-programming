N, K = map(int, input().split())
mat = [[0] * N for _ in range(N)]
for i in range(N):
    for j in range(K-1):
        mat[i][j] = i * (K-1) + j + 1
for i in range(N):
    for j in range(N-K+1):
        mat[i][j+K-1] = N * (K-1) + i * (N - K + 1) + j + 1
print(sum(mat[i][K-1] for i in range(N)))
[print(*row) for row in mat]
