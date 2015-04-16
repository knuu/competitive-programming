n = int(input())
H = [int(input()) for _ in range(n)]
if n <= 2:
    print(n)
    exit(0)
d = []
if H[0] < H[1]:
    d.append([0, -1])
else:
    d.append([0, 1])
for i in range(1, n-1):
    if H[i-1] < H[i] > H[i+1]:
        d.append([i, 1])
    elif H[i-1] > H[i] < H[i+1]:
        d.append([i, -1])
if H[n-2] < H[n-1]:
    d.append([n-1, 1])
else:
    d.append([n-1, -1])

l = len(d)
if l == 2:
    print(n)
    exit(0)
    
ans = 0
start = 0
for i, delta in d:
    if delta == -1:
        ans = max(ans, i - start + 1)
        start = i

if d[l-1][1] == 1:
    ans = max(ans, n - d[l-2][0])

print(ans)
