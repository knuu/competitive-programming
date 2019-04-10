def f(x):
    return x + P / pow(2, x/1.5)
P = float(input())
left, right = 0, 100
for _ in range(10**3):
    mid1, mid2 = (2 * left + right) / 3, (left + 2 * right) / 3
    if f(mid1) < f(mid2):
        right = mid2
    else:
        left = mid1
print('{:.020f}'.format(f(left)))
