N, S, T = map(int, input().split())

dist = 0
while S < T:
    T //= 2
    dist += 1

print(dist if S == T else -1)
