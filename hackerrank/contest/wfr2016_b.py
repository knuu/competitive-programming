N = int(input())
mat = [[int(x) for x in input().split()] for _ in range(N)]
a = list(range(N))
for row in mat:
    if sorted(row) == a:
        row[row.index(0)] = N
        print(*row)
        break
else:
    assert(0)
