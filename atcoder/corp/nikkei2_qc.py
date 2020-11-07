N = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
A_s, B_s = sorted(A), sorted(B)
if any(a > b for a, b in zip(A_s, B_s)):
    print("No")
    quit()
A_idx = [(a, i) for i, a in enumerate(A)]
A_idx.sort()
B = [B[idx] for _, idx in A_idx]
B_idx = [(b, i) for i, b in enumerate(B)]
B_idx.sort()
perm = [0] * N
for i, (_, idx) in enumerate(B_idx):
    perm[idx] = i
cycle_len = 0
used = [False] * N
for i in range(N):
    if used[i]:
        continue
    cnt = 0
    now = i
    while not used[now]:
        used[now] = True
        cnt += 1
        now = perm[now]
    cycle_len += cnt - 1
if cycle_len < N - 1:
    print("Yes")
    quit()

if all(B_idx[i][0] < A_idx[i+1][0] for i in range(N-1)):
    print("No")
else:
    print("Yes")
