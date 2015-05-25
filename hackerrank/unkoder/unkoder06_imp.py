N, x = map(int, input().split())
monster = list(map(int, input().split()))
monster.sort()
level = x
ans = N
levelSum = x
if monster[-1] <= x:
    print(-1)
    exit(0)
for i in range(N):
    if levelSum < monster[i]:
        print(0)
        exit(0)
    else:
        levelSum += monster[i]
for i in range(N):
    if monster[i] <= x:
        continue
    cnt = 0
    cntSum = x
    while cnt < i and cntSum + monster[cnt] <= monster[i]:
        cntSum += monster[cnt]
        cnt += 1
    ans = min(ans, i-cnt) 
print(ans)
