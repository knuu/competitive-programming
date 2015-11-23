for _ in range(int(input())):
    N = int(input())
    ans = N * (N + 1) // 2
    i = 1
    while i <= N:
        ans -= 2 * i
        i <<= 1
    print(ans)
