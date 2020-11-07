N = int(input())
A = [int(x) for x in input().split()]
for i in range(N):
    for j in range(i, N):
        A[i], A[j] = A[j], A[i]
        if sorted(A) == A:
            print("YES")
            quit()
        A[i], A[j] = A[j], A[i]
print("NO")
