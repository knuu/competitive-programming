for _ in range(int(input())):
    N, K = map(int, input().split())
    print(max(N%(i+1) for i in range(K)))
