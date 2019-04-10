for _ in range(int(input())):
    S = input()
    s, m = S.count('s'), S.count('m')
    eaten = [False] * len(S)
    for i, v in enumerate(S):
        if v == 'm':
            if i > 0 and S[i - 1] == 's' and not eaten[i - 1]:
                eaten[i - 1] = True
            elif i < len(S) - 1 and S[i + 1] == 's' and not eaten[i + 1]:
                eaten[i + 1] = True
    s -= sum(eaten)
    if s > m:
        print("snakes")
    elif s == m:
        print("tie")
    else:
        print("mongooses")
