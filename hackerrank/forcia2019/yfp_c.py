from fractions import Fraction
N = int(input())
S = [int(x) for x in input().split()]
T = [int(x) for x in input().split()]
diff = [t - s for s, t in zip(S, T)]
for d in diff:
    f = Fraction(d, diff[0])
    print(f.numerator, f.denominator)
