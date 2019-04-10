while True:
    R0, W0, C, R = map(int, input().split())
    if R0 == W0 == C == R == 0:
        break
    X = 0
    while True:
        if R0 + X * R - C * W0 >= 0:
            print(X)
            break
        else:
            X += 1
