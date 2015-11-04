c = sorted([int(x) for x in input().split()] for _ in range(5))
for i in range(4):
    if c[i][0] >= c[i+1][0] or c[i][1] >= c[i+1][1]:
        print(0)
        break
else:
    print(1)
