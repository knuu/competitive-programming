N, K = map(int, input().split())
W = [int(x) for x in input().split()]
ans = 0
for w in W:
    if w % K == 0:
        ans += w // K
    else:
        ans += w // K + 1
if ans % 2 == 0:
    print(ans // 2)
else:
    print(ans // 2 + 1)
