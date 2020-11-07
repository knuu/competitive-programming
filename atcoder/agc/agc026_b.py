for _ in range(int(input())):
    A, B, C, D = map(int, input().split())
    if A < B or C + D < B:
        print("No")
        continue
    elif C >= B - 1:
        print("Yes")
        continue
    ret = []
    s_set = set()
    now = A
    while True:
        now %= B
        if now in s_set:
            print("Yes", ret)
            break
        else:
            s_set.add(now)
        if now <= C:
            now += D
            ret.append(now)
        else:
            print("No", ret)
            break
