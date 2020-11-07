import bisect
N, K = map(int, input().split())

V = [int(x) for x in input().split()]

ans = 0
for a in range(K+1):
    for b in range(K+1):
        max_CD = min(a + b, min(2*N, K) - (a+b))
        if max_CD < 0 or a + b > N:
            break
        vs = V[:a] + V[N-b:]
        vs.sort()
        i = bisect.bisect_left(vs, 0)
        #print(a, b, max_CD, vs, i, sum(vs[min(i, max_CD):]))
        ans = max(ans, sum(vs[min(i, max_CD):]))
print(ans)
