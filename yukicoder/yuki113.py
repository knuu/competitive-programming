from math import hypot
x, y = 0, 0
for s in input():
    if s == 'N':
        y += 1
    elif s == 'E':
        x += 1
    elif s == 'W':
        x -= 1
    elif s == 'S':
        y -= 1
print(hypot(x, y))
