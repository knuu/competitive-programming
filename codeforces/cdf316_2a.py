N, M = map(int, input().split())
bucket = [0] * N
for i in range(M):
    v = [int(x) for x in input().split()]
    bucket[v.index(max(v))] += 1
print(bucket.index(max(bucket)) + 1)
