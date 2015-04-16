print(sum([1 for l in [list(map(int, input().split())) for _ in range(int(input()))] if l.count(1) >= 2]))
