for _ in range(int(input())):
    N, K = map(int, input().split())
    print("YES" if all(a + b >= K for a, b in zip(sorted(int(x) for x in input().split()), reversed(sorted(int(x) for x in input().split())))) else "NO")
