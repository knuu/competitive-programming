import heapq
N, M = map(int, input().split())
pque = [-int(x) for x in input().split()]
heapq.heapify(pque)

res = M
while res > 0:
    a = heapq.heappop(pque)
    a = -(abs(a) >> 1)
    heapq.heappush(pque, a)
    res -= 1
print(-sum(int(x) for x in pque))
