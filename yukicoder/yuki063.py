L, K = map(int, input().split())
if L % (K*2) == 0:
    print(K*(L//(K*2)-1))
else:
    print(K*(L//(K*2)))
