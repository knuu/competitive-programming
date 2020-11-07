from math import ceil, floor
N = int(input())
info = [[-1] * N for _ in range(N)]
for i in range(N):
    info[i][i] = int(input())
point_sum = sum(info[i][i] for i in range(N))
for _ in range(int(input())):
    a, b, c = map(int, input().split())
    b, c = b-1, c-1
    if a == 0:
        info[b][c] = info[c][c]
    elif a == 1:
        if info[b][c] != -1:
            print(info[c][c], info[c][c])
        else:
            know = [info[b][i] for i in range(N) if info[b][i] != -1]
            K = len(know)
            rest = point_sum - sum(know)
            print(max(0, ceil(rest - 100 * (N - K - 1))), min(100, rest))
    
