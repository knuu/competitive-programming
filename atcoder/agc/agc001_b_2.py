from fractions import gcd
N, X = map(int, input().split())
print(3 * (N - gcd(N, X)))
