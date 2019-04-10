import heapq
N, K = map(int, input().split())
que = []
for _ in range(N):
    a, b = map(int, input().split())
    heapq.heappush(que, (a, b))
ans = 0
for _ in range(K):
    a, b = heapq.heappop(que)
    ans += a
    heapq.heappush(que, (a + b, b))
print(ans)
