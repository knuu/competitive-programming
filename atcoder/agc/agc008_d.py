N = int(input())
ans = [-1] * (N ** 2)
X = [int(x)-1 for x in input().split()]
for i, x in enumerate(X):
    ans[x] = i+1
left, right = [], []
for i in range(N):
    l_cnt, r_cnt = i, N - (i+1)
    left.extend([(X[i], i+1)] * l_cnt)
    right.extend([(X[i], i+1)] * r_cnt)
l, r = 0, N ** 2 - 1
left.sort()
right.sort(reverse=True)
for _, x in left:
    while ans[l] != -1:
        l += 1
    ans[l] = x
for _, x in right:
    while ans[r] != -1:
        r -= 1
    ans[r] = x
counter = [[] for _ in range(N)]
for i, a in enumerate(ans):
    counter[a-1].append(i)
if all(counter[i].index(x) == i for i, x in zip(range(N), X)):
    print("Yes")
    print(*ans)
else:
    print("No")
