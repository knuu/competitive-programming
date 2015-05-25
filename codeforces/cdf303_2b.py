s = input()
t = input()
diffcnt = 0
for i, j in zip(s, t):
    if i != j: diffcnt += 1
if diffcnt % 2 == 1:
    print('impossible')
    exit(0)
cnt = 0
ans = []
for i, j in zip(s, t):
    if i == j:
        ans.append(i)
    else:
        ans.append(i if cnt % 2 == 0 else j)
        cnt += 1
print(''.join(ans))
    
