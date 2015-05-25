from copy import deepcopy
def inboard(x, y):
    return 0 <= x < 10 and 0 <= y < 10
while True:
    sr, sc = map(int, raw_input().split())
    if (sr, sc) == (0, 0): break
    N = input()
    pointList = map(int, raw_input().split())
    points = []
    for i in range(0, 2*N, 2):
        points.append((pointList[i], pointList[i+1]))
    canReach = set()
    canReach.add((sr, sc))
    jump = [(-2, -1), (-2, 0), (-2, 1),
            (-1, -2), (0, -2), (1, -2),
            (2, -1), (2, 0), (2, 1),
            (-1, 2), (0, 2), (1, 2)]
    for spr, spc in points:
        newset = set()
        for r, c in canReach:
            for dr, dc in jump:
                nr, nc = r + dr, c + dc
                if inboard(nr, nc) and spr-1 <= nr <= spr+1 and spc-1 <= nc <= spc+1:
                    newset.add((nr, nc))
        canReach = deepcopy(newset)
    print("OK" if len(canReach) > 0 else "NA")
