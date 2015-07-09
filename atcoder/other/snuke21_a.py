n = int(input())
k = int(pow(1+8*n, 0.5) - 1) // 2
print(k if k * (k + 1) // 2 == n else -1)
