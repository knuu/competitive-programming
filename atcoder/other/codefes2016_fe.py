N, A = map(int, input().split())

ans = N

for k in range(50):
    left, right = 1, int(pow(N, 1/(k+1))) + 1
    while left + 1 < right:
        mid = (left + right) >> 1
        if mid ** (k+1) >= N:
            right = mid
        else:
            left = mid
    for i in range(k+1):
        if ((right - 1) ** i) * (right ** (k+1 - i)) >= N:
            ans = min(ans, A * k + i * (right - 1) + (k+1 - i) * right)
print(ans)
