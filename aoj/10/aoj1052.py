while True:
    n = input()
    if n == 0: break
    info = []
    for i in range(n):
        lu, w = map(int, raw_input().split())
        info.append((w, lu))
    info.sort()
    lu_sum = 0
    flag = True
    for w, lu in info:
        lu_sum += lu
        if lu_sum > w:
            flag = False
    print("Yes" if flag else "No")
