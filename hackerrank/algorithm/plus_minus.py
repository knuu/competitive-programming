N = int(input())
plus, minus, zero = 0, 0, 0
for i in input().split():
    i = int(i)
    if i > 0:
        plus += 1
    elif i < 0:
        minus += 1
    else:
        zero += 1
print('{:.3f}'.format(plus/N))
print('{:.3f}'.format(minus/N))
print('{:.3f}'.format(zero/N))
