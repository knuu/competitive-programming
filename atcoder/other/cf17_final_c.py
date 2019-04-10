N = int(input())
D = [int(x) for x in input().split()]
D.append(0)
D.sort()
ans = []
for i in range(N + 1):
    if i % 2 == 0:
        ans.append(D[i])
    else:
        ans.append((24 - D[i]) % 24)
ans.sort()
print(min(min(ans[i + 1] - ans[i] for i in range(N)), 24 - ans[-1]))
