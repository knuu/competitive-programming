N = int(input())
A = [0]
for x in map(int, input().split()):
    A.append(x)
    A[-1] += A[-2]
ans = int(1e18)
for i in range(N - 1):
    ans = min(ans, abs(A[i+1] - (A[N] - A[i+1])))
print(ans)
