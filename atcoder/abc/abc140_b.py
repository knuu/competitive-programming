N = int(input())
A = [int(x)-1 for x in input().split()]
B = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]
ans = 0
for i, a in enumerate(A):
    ans += B[a]
    if i < N-1 and a + 1 == A[i+1]:
        ans += C[a]
print(ans)
