N = int(input())
B = [int(x) for x in input().split()]
A = [10**5] * N
for i, b in enumerate(B):
    A[i] = min(A[i], b)
    A[i+1] = min(A[i+1], b)
print(sum(A))
