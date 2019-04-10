R, B = map(int, input().split())
x, y = map(int, input().split())
left, right = (R - B // y) // x if B // y <= R else 0, R // x if R // x <= B else B
def f(a):
    if a <= B:
        return a + min((B - a) // y, R - a * x)
    else:
        return B
while left + 2 < right:
    mid1 = left + (right - left) // 3
    mid2 = right - (right - left) // 3
    if f(mid1) > f(mid2):
        right = mid2
    else:
        left = mid1
print(max([f(left), f(right), f((left+right)//2)]))
