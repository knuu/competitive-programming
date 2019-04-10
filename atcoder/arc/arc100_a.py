def f(A, b):
    return sum(abs(a - (b + i + 1)) for i, a in enumerate(A))
N = int(input())
A = [int(x) for x in input().split()]
left, right = -10**9, 10**9
while left + 2 < right:
    diff = (right - left) // 3
    m1 = left + diff
    m2 = m1 + diff
    if f(A, m1) > f(A, m2):
        left = m1
    else:
        right = m2
print(min(f(A, i) for i in range(left, right + 1)))
