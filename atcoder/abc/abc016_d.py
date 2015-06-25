ax, ay, bx, by = map(int, input().split())
n = int(input())
s = [list(map(int, input().split())) for i in range(n)]

def iscross(a1x, a1y, a2x, a2y, b1x, b1y, b2x, b2y):
    # 符号付き三角形(ベクトルの外積使うアレ)
    S1 = (a2x-a1x)*(b1y-a1y) - (a2y-a1y)*(b1x-a1x)
    S2 = (a2x-a1x)*(b2y-a1y) - (a2y-a1y)*(b2x-a1x)
    if S1*S2 < 0:
        return True
    else:
        return False

cnt = 0
x, y = 0, 1
for i in range(n):
    t1 = iscross(ax,ay,bx,by,s[i][x],s[i][y],s[(i+1)%n][x],s[(i+1)%n][y])
    t2 = iscross(s[i][x],s[i][y],s[(i+1)%n][x],s[(i+1)%n][y],ax,ay,bx,by)
    if t1 and t2 : cnt += 1



print(int(cnt/2) + 1)
    
