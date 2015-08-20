for _ in range(int(input())):
    X = int(input())
    n = 1
    ans = 0
    while n <= X:
        if X % n == 0:
            ans += 1
        n <<= 1
    print(ans)
