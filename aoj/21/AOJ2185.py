d = int(input())
for _ in range(d):
    x, y, w, h = map(int, input().split())
    n = int(input())
    ans = 0
    for i in range(n):
        cx, cy = map(int, input().split())
        if x <= cx <= x + w and y <= cy <= y + h:
            ans += 1
    print(ans)
