from itertools import permutations


def check(queen):
    for r1, c1 in queen:
        if not all((r1 == r2 and c1 == c2) or (r1 + c1 != r2 + c2 and r1 - c1 != r2 - c2) for r2, c2 in queen):
            return False
    return True


N = int(input())
row, col = list(range(8)), list(range(8))
queen = []
for _ in range(N):
    r, c = map(int, input().split())
    queen.append((r, c))
    row.remove(r)
    col.remove(c)
for l in permutations(col):
    queen_tmp = queen[:]
    for r, c in zip(row, l):
        queen_tmp.append((r, c))
    if check(queen_tmp):
        board = [''.join('Q' if (r, c) in queen_tmp else '.' for c in range(8)) for r in range(8)]
        print(*board, sep='\n')
        break
