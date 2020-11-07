N, K = map(int, input().split())
acc = [0.0]
for x in map(int, input().split()):
    acc.append((1 + x) / 2)
    acc[-1] += acc[-2]
ans = 0.0
for start in range(N - K + 1):
    ans = max(ans, acc[start + K] - acc[start])
print(ans)
