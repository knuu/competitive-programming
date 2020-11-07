N, A, B = map(int, input().split())
if abs(A - B) % 2 == 0:
    print(abs(A - B) // 2)
else:
    left = A + (B - A - 1) // 2
    right = N - B + 1 + (B - A - 1) // 2
    print(min(right, left))
