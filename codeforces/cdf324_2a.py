N, T = map(int, input().split())
if N == 1:
    print(T if T != 10 else -1)
else:
    ans = int('1' + '0' * (N-1))
    for i in range(10):
        if (ans + i) % T == 0:
            print(ans + i)
            break
