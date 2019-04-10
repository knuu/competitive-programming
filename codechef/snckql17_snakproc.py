for _ in range(int(input())):
    L = int(input())
    S = input()
    cnt = 0
    flag = True
    for s in S:
        if s == 'H':
            flag &= cnt == 0
            cnt += 1
        elif s == 'T':
            flag &= cnt == 1
            cnt -= 1
    flag &= cnt == 0
    print("Valid" if flag else "Invalid")
