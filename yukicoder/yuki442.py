from fractions import gcd
A, B = map(int, input().split())
print(gcd(A+B, A*B))
