L = int(input())
N = L.bit_length()
res = L - (1 << (N - 1))
start = 1 << (N - 1)

ans = []
for i in range(N - 1):
    ans.append((i + 1, i + 2, 0))
    ans.append((i + 1, i + 2, 1 << (N - i - 2)))

for i in reversed(range(N)):
    if res >= (1 << i):
        ans.append((1, N - i, start))
        start += (1 << i)
        res -= 1 << i

print(N, len(ans))
for edge in ans:
    print(*edge)
