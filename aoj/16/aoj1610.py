import collections
import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input
idx = 0
queries = collections.defaultdict(list)
while True:
    M, N = map(int, input().split())
    if M == N == 0:
        break
    queries[M].append((N, idx))
    idx += 1

for k in queries.keys():
    queries[k].sort()

INF = 7368791
P = [False] * (INF + 1)
output = [0] * idx

for k in queries.keys():
    for i in range(INF + 1):
        P[i] = False

    cnt = 0
    ans = []
    for i in range(k, INF + 1):
        if cnt >= queries[k][-1][0]:
            break
        if not P[i]:
            ans.append(i)
            for j in range(i, INF + 1, i):
                P[j] = True
            cnt += 1
    for i in range(M, INF + 1):
        if not P[i]:
            ans.append(i)
    for v, idx in queries[k]:
        output[idx] = ans[v]
print('\n'.join(map(str, output)))
