from math import sqrt
R, N, M = map(int, input().split())
if M != 1:
    assert(False)
ans = 0
if N % 2 == 0:
    ans += 2 * R
for i in range((N-1) // 2):
    ans += 2 * sqrt(R ** 2 - (R - 2 * R / N * (i + 1)) ** 2)
print(ans)
