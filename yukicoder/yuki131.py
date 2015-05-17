x, y, d = map(int, input().split())
print(max(d + 1 - max(d - x, 0) - max(d - y, 0), 0))
