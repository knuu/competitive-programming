N, K = map(int, input().split())
a = sorted(map(int, input().split()))
b = sorted(map(int, input().split()))

low, high = a[0]*b[0]-1, a[-1] * b[-1]
while high - low > 1:
    mid = (low + high) // 2
    cnt = 0
    now = N - 1
    for i in range(N):
        while now >= 0 and a[i] * b[now] > mid:
            now -= 1
        cnt += now + 1
    if cnt < K:
        low = mid
    else:
        high = mid

print(high)
