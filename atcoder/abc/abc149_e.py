import bisect
N, M = map(int, input().split())
A = [int(x) for x in input().split()]
A.sort()
INF = 10 ** 9
A.append(INF)

left, right = 0, 2 * max(A)
while left + 1 < right:
    mid = (left + right) >> 1
    cnt = sum(N - bisect.bisect_left(A, mid-A[i]) for i in range(N))
    if cnt >= M:
        left = mid
    else:
        right = mid
acc = [0]
for i in range(N):
    acc.append(acc[-1] + A[i])
ans = 0
cnt = 0
for i in range(N):
    idx = bisect.bisect_left(A, left-A[i])
    cnt += N - idx
    ans += (N - idx) * A[i] + acc[N] - acc[idx]
ans -= (cnt - M) * left
print(ans)
