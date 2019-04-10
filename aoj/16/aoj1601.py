while True:
    N = int(input())
    if N == 0:
        break
    words = [len(input()) for _ in range(N)]

    for i in range(N):
        now = i
        tanku = [5, 7, 5, 7, 7][::-1]
        while tanku:
            while tanku[-1] > 0:
                tanku[-1] -= words[now]
                now += 1
            if tanku[-1] == 0:
                tanku.pop()
            else:
                break
        else:
            print(i + 1)
            break
