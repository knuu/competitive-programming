print(int(sum((lambda a, b: a*b)(*map(int, input().split())) for _ in range(int(input()))) * 1.05))
