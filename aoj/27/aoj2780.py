N = int(input())
A = [int(x) for x in input().split()]
ans = -1
for i in range(N):
    for j in range(i + 1, N):
        num = [int(x) for x in str(A[i] * A[j])]
        if all(num[i] + 1 == num[i + 1] for i in range(len(num) - 1)) and ans < A[i] * A[j]:
            ans = A[i] * A[j]
print(ans)
