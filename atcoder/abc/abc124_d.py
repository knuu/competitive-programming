N, K = map(int, input().split())
S = input()
starts = []
idx = 0
while idx < len(S):
    starts.append(idx)
    while idx < len(S) and S[starts[-1]] == S[idx]:
        idx += 1
starts.append(len(S))
ans = 0
for i, start in enumerate(starts[:-1]):
    if S[start] == '0':
        stop = starts[min(len(starts) - 1, i + 2 * K)]
    else:
        stop = starts[min(len(starts) - 1, i + 2 * K + 1)]
    ans = max(ans, stop - start)
print(ans)
