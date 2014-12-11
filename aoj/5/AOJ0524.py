while True:
    m = int(input())
    if m == 0: break
    star = list({tuple(map(int, input().split())) for i in range(m)})
    sx, sy = star[0]
    
    n = int(input())
    starset = {tuple(map(int, input().split())) for i in range(n)}
    for x, y in starset:
        flag = True
        for j in range(len(star)-1):
            dx = x + star[j+1][0] - sx
            dy = y + star[j+1][1] - sy
            if (dx, dy) not in starset:
                flag = False
                break

        if flag == True:
            print(x - sx, y - sy)
            break
    
