N, M, T = map(int, input().split())
A = [int(x) for x in input().split()]
print(A[0] - M + max(T - A[-1] - M, 0) + sum(max(0, A[i+1] - A[i] - 2 * M) for i in range(N - 1)))
