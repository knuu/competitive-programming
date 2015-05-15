N, M = map(int, input().split())
data = [list(map(int, input().split())) for i in range(N)]
K = int(input())
data.sort(key=lambda x: x[K])
for d in data:
    print(' '.join([str(num) for num in d]))
