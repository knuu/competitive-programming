for _ in range(int(input())):
    _, K = map(int, input().split())
    print("YES" if sum(x <= 0 for x in map(int, input().split())) < K else "NO")
