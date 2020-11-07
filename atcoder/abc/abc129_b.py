N = int(input())
W = [int(x) for x in input().split()]
acc = [0]
for w in W:
    acc.append(acc[-1] + w)
ans = acc[-1]
for i in range(N-1):
    a = acc[-1] - acc[i+1]
    b = acc[i+1]
    ans = min(ans, abs(a-b))
print(ans)
