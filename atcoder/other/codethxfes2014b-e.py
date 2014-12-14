import sys
sys.setrecursionlimit(3000)

def check(rs, cs):
    table[rs][cs] = 2
    if (rs, cs) == (rg, cg): return True
    if rs > 0 and table[rs - 1][cs] == 1 and check(rs - 1, cs):
        return True
    if cs > 0 and table[rs][cs - 1] == 1 and check(rs, cs - 1):
        return True
    if rs < r - 1 and table[rs + 1][cs] == 1 and check(rs + 1, cs):
        return True
    if cs < c - 1 and table[rs][cs + 1] == 1 and check(rs, cs + 1):
        return True
    return False
    

r, c = map(int, input().split())
table = [[0] * c for _ in range(r)]
rs, cs = map(lambda x:int(x) - 1, input().split())
rg, cg = map(lambda x:int(x) - 1, input().split())
n = int(input())
draw = [list(map(int, input().split())) for _ in range(n)]
for ri, ci, hi, wi in draw:
    ri -= 1
    ci -= 1
    for i in range(ri, ri+hi):
        for j in range(ci, ci+wi):
            table[i][j] = 1

if table[rs][cs] != 1 or table[rg][cg] != 1:
    print('NO')
else:
    print('YES' if check(rs, cs) else 'NO')
