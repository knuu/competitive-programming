while True:
    N = int(input())
    if not N:
        break
    A = sorted(map(int, input().split()))
    print(min(A[i+1] - A[i] for i in range(N-1)))
