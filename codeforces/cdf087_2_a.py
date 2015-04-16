n = int(input())
ans = 0
bus = 0
for _ in range(n):
    a, b = map(int, input().split())
    bus += b - a
    ans = max(ans, bus)
print(ans)
