source = [list(map(int, input().split())) for _ in range(int(input()))]
s = [a + 4*b for a, b in source]
print(-1 if 0 < len(list(filter(lambda x: x % 2 == 0, s))) < len(s) else sum((max(s)-si)//2 for si in s))
