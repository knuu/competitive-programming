from math import sqrt
while True:
    R, N = map(int, input().split())
    if not (R | N):
        break
    geta = 20
    buildings = [0] * (geta * 2)
    for _ in range(N):
        xl, xr, h = map(int, input().split())
        for i in range(xl + geta, xr + geta):
            buildings[i] = max(buildings[i], h)

    print(min(buildings[i] - sqrt(R * R - (i - geta + (i < geta)) * (i - geta + (i < geta))) + R for i in range(-R + geta, R + geta)))
