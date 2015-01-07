n = int(input())
num = input()
num = [list(num) for _ in range(10)]
for i in range(10):
    for j in range(n):
        num[i][j] = (int(num[i][j]) + i) % 10

col = []
for i in range(10):
    for j in range(n):
        col.add(num[i][j:]+num[i][:j])

ans = ''.join(list(map(str, min(col))))
print(ans)

