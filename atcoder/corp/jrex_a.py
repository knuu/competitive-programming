N = int(input())
A = [[int(x) for x in input().split()] for _ in range(N)]
ans, cnt = 0, 0
for a, b in reversed(A):
    a += cnt
    if a % b == 0:
        continue
    d = a // b + 1
    cnt += b * d - a
    ans += b * d - a
print(ans)
