N = int(input())
A = list(map(int, input().split()))
A.sort()

left, right = 0, 2*N-1
moist = A.count(0) // 2
while left < right and A[left] < 0 and A[right] > 0:
    if abs(A[left]) == A[right]:
        moist += 1
        left += 1
        right -= 1
    elif abs(A[left]) > A[right]:
        left += 1
    else:
        right -= 1

left, right = 0, 2*N-1
wet = 0
while left < right:
    if A[left] + A[right] <= 0:
        left += 1
    else:
        wet += 1
        left += 1
        right -= 1


left, right = 0, 2*N-1
dry = 0
while left < right:
    if A[left] + A[right] >= 0:
        right -= 1
    else:
        dry += 1
        left += 1
        right -= 1

print(dry, wet, moist)
