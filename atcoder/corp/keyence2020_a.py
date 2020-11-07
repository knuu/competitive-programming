H, W, N = int(input()), int(input()), int(input())
M = max(H, W)
print(N // M + (N % M != 0))
