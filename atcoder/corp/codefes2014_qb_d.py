N = int(input())
H = [int(input()) for _ in range(N)]

left, right = [-1] * N, [N] * N
for i, h in enumerate(H):
    now = i-1
    while now != -1 and H[now] <= h:
        now = left[now]
    left[i] = now
for i, h in reversed(zip(range(N), H)):
    now = i+1
    while now != N and H[now] <= h:
        now = right[now]
    right[i] = now

for i in range(N):
    print(right[i] - left[i] - 2)
