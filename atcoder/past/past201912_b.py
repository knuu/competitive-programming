N = int(input())
A = [int(input()) for _ in range(N)]

for i in range(1, N):
    if A[i-1] < A[i]:
        print("up", A[i] - A[i-1])
    elif A[i-1] > A[i]:
        print("down", A[i-1] - A[i])
    else:
        print("stay")
