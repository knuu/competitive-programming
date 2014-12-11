n, m = map(int, input().split())
array = [list(map(int, input().split())) for _ in range(n)]
vec = [int(input()) for _ in range(m)]

for i in range(n):
    print(sum([array[i][j] * vec[j] for j in range(m)]))




        
