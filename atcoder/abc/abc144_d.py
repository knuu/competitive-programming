import math

a, b, x = map(int, input().split())
vol = a * a * b
if x * 2 <= vol:
    l = 2 * x / (a * b)
    arc = math.atan(b / l)
else:
    f1, f2 = a / 2, b - x / (a * a)
    arc = math.atan(f2 / f1)
print(arc * 180 / math.acos(-1))
