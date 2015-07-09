def calc(x):
    ret = 0
    for i in range(N):
        ret += min(M, x // (i+1))
    return ret

N, M, K = map(int, input().split())
N, M = sorted([N, M])
low, high = 0, K+1
while high - low > 1:
    mid = (low + high) // 2
    if calc(mid) < K:
        low = mid
    else:
        high = mid
 
print(high)
