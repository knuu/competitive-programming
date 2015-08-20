for _ in range(int(input())):
    M, x, y = map(int, input().split())
    cops = [int(x)-1 for x in input().split()]
    can_hide = [True] * 100
    for c in cops:
        can_hide[c] = False
        i = 1
        while i <= x * y:
            if c-i >= 0:
                can_hide[c-i] = False
            if c+i < 100:
                can_hide[c+i] = False
            i += 1
    print(sum(can_hide))
