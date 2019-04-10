import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input
N, K = map(int, input().split())
A = [int(x) for x in input().split()]
accum = [[0, 0] for _ in range(N + 1)]
for i in range(N):
    accum[i+1][0] += accum[i][0] + A[i]
    accum[i+1][1] += accum[i][1] + max(A[i], 0)
ans = 0
for i in range(N-(K-1)):
    cand = accum[i+K][0] - accum[i][0] + accum[i][1] - accum[0][1] + accum[N][1] - accum[i+K][1]
    ans = max(ans, cand, accum[i][1] - accum[0][1] + accum[N][1] - accum[i+K][1])
print(ans)
