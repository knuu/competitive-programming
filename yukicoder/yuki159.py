p, q = map(float, input().split())
print('YES' if (1-p) * q < p * (1-q) * q else 'NO')
