import heapq

import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input

N, Q = map(int, input().split())
INF = 10 ** 9
ans = [INF] * Q
stops = [0] * N
times = []
for i in range(N):
    s, t, x = map(int, input().split())
    times.append((s-x, 0, i))
    times.append((t-x, -1, i))
    stops[i] = x
for i in range(Q):
    d = int(input())
    times.append((d, 1, i))

times.sort()
pque = []
used = [False] * N
for t, k, i in times:
    #print(t, k, i)
    if k == -1:
        used[i] = True
    elif k == 0:
        heapq.heappush(pque, (stops[i], i))
    else:
        while pque:
            x, j = heapq.heappop(pque)
            if not used[j]:
                ans[i] = min(ans[i], x)
                heapq.heappush(pque, (x, j))
                break
for x in ans:
    if x != INF:
        print(x)
    else:
        print(-1)
