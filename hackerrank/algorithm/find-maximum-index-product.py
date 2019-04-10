N = int(input())
A = [int(x) for x in input().split()]

left = [-1] * N
for i in range(1, N):
    now = i-1
    while now != -1 and A[now] <= A[i]:
        now = left[now]
    left[i] = now

right = [-1] * N
for i in reversed(range(N-1)):
    now = i+1
    while now != -1 and A[now] <= A[i]:
        now = right[now]
    right[i] = now
print(max((l+1) * (r+1) for l, r in zip(left, right)))
