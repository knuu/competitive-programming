N = int(input())
robots = []
for _ in range(N):
    X, L = map(int, input().split())
    robots.append((X+L, X-L))
robots.sort()
ans = 0
last_end = -10 ** 10
for end, start in robots:
    if last_end <= start:
        last_end = end
        ans += 1
print(ans)
