A, B, C, K = map(int, input().split())
ans = A - B if K % 2 == 0 else B - A
print("Unfair" if abs(ans) > 10 ** 18 else ans)
