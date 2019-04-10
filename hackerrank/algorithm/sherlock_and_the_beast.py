for _ in range(int(input())):
    N = int(input())
    for i in reversed(range(N//3+1)):
        f, t = i * 3, N - i * 3
        if t % 5 == 0:
            print('5' * f + '3' * t)
            break
    else:
        print(-1)
