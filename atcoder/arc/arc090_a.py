N = int(input())
A1 = [int(x) for x in input().split()]
A2 = [int(x) for x in input().split()]
acc1, acc2 = [0], [0]
for i in range(N):
    acc1.append(acc1[-1] + A1[i])
    acc2.append(acc2[-1] + A2[i])
ans = 0
for i in range(N):
    ans = max(ans, acc1[i+1] + acc2[-1] - acc2[i])
print(ans)
