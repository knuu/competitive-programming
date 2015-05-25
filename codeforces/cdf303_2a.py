N = int(input())
mat = [list(map(int, input().split())) for _ in range(N)]
ans = []
for i in range(N):
    flag = True
    for j in range(N):
        if mat[i][j] == 3 or mat[i][j] == 1:
            flag = False
    if flag == True:
        ans.append(i+1)
if len(ans) == 0:
    print(0)
else:
    print(len(ans))
    print(*ans)
