N, h = map(int, input().split())
print(sum(2 if a > h else 1 for a in [int(x) for x in input().split()]))
