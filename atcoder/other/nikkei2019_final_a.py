N = int(input())
A = [int(x) for x in input().split()]

acc = [0]
for a in A:
    acc.append(acc[-1] + a)

for l in range(N):
    left, right = 0, l + 1
    ans = 0
    while right <= N:
        ans = max(ans, acc[right] - acc[left])
        left, right = left + 1, right + 1
    print(ans)
