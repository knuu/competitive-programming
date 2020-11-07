A, B, K = map(int, input().split())
if A >= K:
    A -= K
    print(A, B)
else:
    A, B = 0, max(0, B - (K - A))
    print(A, B)
