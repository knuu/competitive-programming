N, K = map(int, input().split())
A = [int(a) for a in input().split()]
A.sort(reverse=True)

for i in range(N - 1):
    A[i + 1] += A[i]
for i in range(N):
    if A[i] >= K:
        print(i + 1)
        break
else:
    print(-1)
