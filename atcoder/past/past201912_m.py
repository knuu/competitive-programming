N, M = map(int, input().split())
mons = []
for _ in range(N):
    A, B = map(int, input().split())
    mons.append((A, B))
mon_help = []
for _ in range(M):
    C, D = map(int, input().split())
    mon_help.append((C, D))

left, right = 0, 10**9
for i in range(1000):
    mid = (left + right) / 2
    mon_arr = []
    for a, b in mons:
        mon_arr.append((b - mid * a, 0))
    for c, d in mon_help:
        mon_arr.append((d - mid * c, 1))
    mon_arr.sort(reverse=True)
    #print(left, right, mon_arr)
    help_flag = False
    val, cnt = 0, 0
    for v, is_help in mon_arr:
        if is_help:
            if help_flag:
                continue
            help_flag = True
            val += v
        else:
            val += v
        cnt += 1
        if cnt == 5:
            break
    if val >= 0:
        left = mid
    else:
        right = mid
print("{:.20f}".format(left))
