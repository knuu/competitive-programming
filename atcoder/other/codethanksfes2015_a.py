A, B = int(input()), int(input())
if A * B > 0:
    print(2 * max(abs(A), abs(B)))
else:
    print(2 * abs(A) + 2 * abs(B))
