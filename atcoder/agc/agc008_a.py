x, y = map(int, input().split())
assert(x != y)
if x <= y:
    if -x <= y:
        print(min(abs(x-y), abs(-x-y) + 1))
    else:
        print(min(abs(x-y), abs(x-(-y)) + 1))
else:
    if -x <= y:
        print(min(abs(-x-y), abs(-x-(-y)) + 1) + 1)
    else:
        print(min(abs(-y-x), abs(-y-(-x)) + 1) + 1)
