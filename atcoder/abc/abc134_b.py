N, D = map(int, input().split())
dd = (2 * D + 1)
print(N // dd + (N % dd != 0))
