from itertools import permutations
N, M, L = map(int, input().split())
boxes = [int(x) for x in input().split()]
print(max((N//b[0])*(M//b[1])*(L//b[2]) for b in permutations(boxes, 3)))
