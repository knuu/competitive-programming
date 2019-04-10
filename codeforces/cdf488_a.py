N, M = map(int, input().split())
X = [int(x) for x in input().split()]
Y = [int(x) for x in input().split()]
print(*[x for x in X if x in Y])
