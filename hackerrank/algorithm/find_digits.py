for _ in range(int(input())):
    N = int(input())
    print(sum(1 for x in str(N) if int(x) and not N % int(x)))
