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
