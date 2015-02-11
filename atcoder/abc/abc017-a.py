p = [map(int, input().split()) for _ in range(3)]
print(sum(s * e // 10 for s, e in p))
