n,k = map(int, input().strip().split())
x = [list(map(int, input().strip().split())) for x in range(n)]

for i in range(n-1):
    t = []
    for j in range(len(x[0])):
        for k in range(len(x[i+1])):
            t.append(x[0][j] ^ x[i+1][k])
    x[0] = list(set(t))
            
if x[0].count(0):
    print('Found')
else:
    print('Nothing')
