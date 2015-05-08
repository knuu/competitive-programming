eps = 1e-10

def add(a, b):
    return 0 if abs(a + b) < eps * (abs(a) + abs(b)) else a + b

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, p):
        return Point(add(self.x, p.x), add(self.y, p.y))

    def __sub__(self, p):
        return Point(add(self.x, -p.x), add(self.y, -p.y))

    def __mul__(self, d):
        return Point(self.x * d, self.y * d)

    def dot(self, p):
        return add(self.x * p.x, self.y * p.y)

    def det(self, p):
        return add(self.x * p.y, -self.y * p.x)

    def __str__(self):
        return "({}, {})".format(self.x, self.y)

def convex_hull(ps):
    ps = [Point(x, y) for x, y in sorted([(p.x, p.y) for p in ps])]
    upper_hull = get_bounds(ps)
    ps.reverse()
    lower_hull = get_bounds(ps)
    del upper_hull[-1]
    del lower_hull[-1]
    upper_hull.extend(lower_hull)
    return upper_hull

def get_bounds(ps):
    qs = [ps[0], ps[1]]
    for p in ps[2:]:
        while len(qs) > 1 and (qs[-1] - qs[-2]).det(p - qs[-1]) <= 0:
            del qs[-1]
        qs.append(p)
    return qs


qs = []
for i in range(5):
    x, y = map(int, input().split())
    qs.append(Point(x, y))
qs = convex_hull(qs)
print('YES' if len(qs) == 5 else 'NO')
    

