from math import sin, acos
N, Q = map(int, input().split())
obs = [tuple(map(int, input().split())) for _ in range(N)]
def dist(v):
    return sum(x ** 2 for x in v)

def cos(v1, v2):
    return sum(x * y for x, y in zip(v1, v2)) / pow(dist(v1), 0.5) / pow(dist(v2), 0.5)


for _ in range(Q):
    sx, sy, sz, dx, dy, dz = map(int, input().split())
    v_oa = (dx - sx, dy - sy, dz - sz)
    ans = 0
    for x, y, z, r, l in obs:
        v_or = (x - sx, y - sy, z - sz)
        print(dist(v_or), sin(acos(cos(v_or, v_oa))), dist(v_or) * pow(sin(acos(cos(v_or, v_oa))), 2), r * r)
        if cos(v_or, v_oa) >= 0 and dist(v_or) * pow(sin(acos(cos(v_or, v_oa))), 2) <= r * r:
            ans += l
    print(ans)
