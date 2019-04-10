from fractions import gcd
for _ in range(int(input())):
    A, B, C, D = map(int, input().split())
    print(min((A - B) % gcd(C, D), (B - A) % gcd(C, D)))
