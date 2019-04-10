N = int(input())
MAX_N = int(1e5) + 2
acc = [0] * (MAX_N + 1)
acc[0] += 1
acc[MAX_N] -= 1
for _ in range(N):
    a, b = map(int, input().split())
    acc[a] += 1
    acc[b + 1] -= 1
for i in range(MAX_N):
    acc[i + 1] += acc[i]
for i in reversed(range(MAX_N)):
    if acc[i] >= i:
        print(i - 1)
        break
