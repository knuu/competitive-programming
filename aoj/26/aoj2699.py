while True:
    D, E = map(int, input().split())
    if D == E == 0:
        break
    print("{:.020f}".format(min(abs(pow(x ** 2 + (D - x) ** 2, 0.5) - E) for x in range(D + 1))))
