import itertools
N = int(input())
P = tuple(int(x) for x in input().split())
Q = tuple(int(x) for x in input().split())

perms = list(itertools.permutations(range(1, N + 1)))
print(abs(perms.index(P) - perms.index(Q)))
