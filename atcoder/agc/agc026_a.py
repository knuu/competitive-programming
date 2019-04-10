N = int(input())
A = [int(x) for x in input().split()]
A.append(-1)
start = 0
ans = 0
for i in range(N):
    if A[i] != A[i + 1]:
        ans += (i - start + 1) // 2
        start = i + 1
print(ans)
