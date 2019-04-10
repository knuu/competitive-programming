N, W, H = map(int, input().split())
row, col = [0] * (H + 1), [0] * (W + 1)
for _ in range(N):
    x, y, w = map(int, input().split())
    row[max(0, y - w)] += 1
    row[min(H, y + w)] -= 1
    col[max(0, x - w)] += 1
    col[min(W, x + w)] -= 1
for i in range(H):
    row[i + 1] += row[i]
for i in range(W):
    col[i + 1] += col[i]
print("Yes" if all(x > 0 for x in row[:-1]) or all(x > 0 for x in col[:-1]) else "No")
