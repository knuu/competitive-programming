N = int(input())
eff = sorted((lambda i, g, d: (g - 30000 * d, i+1))(i, *map(int, input().split())) for i in range(N))
if eff[-1][0] * 6 >= 30000 * 100:
    print('YES')
    print(*[eff[-1][1]]*6, sep='\n')
else:
    print('NO')
