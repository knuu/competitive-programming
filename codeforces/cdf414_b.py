N, H = map(int, input().split())
prev = 0.0
ans = []
for i in range(N - 1):
    now = pow((i + 1) / N, 0.5) * H
    ans.append("{:.20f}".format(now - prev))
    now = prev
print(*ans)
