def find(direction, p):
    if p in near:
        return find(direction, near[p][direction])
    else:
        return p

def makeNear(direction, here):
    x, y = here
    dx, dy = dxy[direction]
    rdx, rdy = dxy[(direction+2)%4]
    nextx, nexty = find(direction, here)
    
    xynear = [None for _ in range(4)]
    
    xynear[direction] = (nextx + dx, nexty + dy)
    near[(x, y)][direction] = xynear[direction]
    
    xynear[(direction+2)%4] = (x + rdx, y + rdy)

    for vert in [(direction+1)%4, (direction+3)%4]:
        vdx, vdy = dxy[vert]
        xynear[vert] = (nextx + vdx, nexty + vdy)
        
    near[(nextx, nexty)] = xynear
    return (nextx, nexty)

K = int(input())
S = input()
dxy = [(-1, 0), (0, 1), (1, 0), (0, -1)]

here = (0, 0)
near = {here: [(-1, 0), (0, 1), (1, 0), (0, -1)]}
D = {'L':0, 'R':2, 'U':1, 'D':3}

for d in S:
    here = makeNear(D[d], here)

#    print(x, y)
#    for k in sorted(list(near.keys())): print(k, near[k])
    
print(*here)
