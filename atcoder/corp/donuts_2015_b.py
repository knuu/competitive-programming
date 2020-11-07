import itertools
N, M = map(int, input().split())
A = list(map(int, input().split()))
combo = []
for _ in range(M):
    B, _, *M = map(int, input().split())
    combo.append((B, set(m-1 for m in M)))
print(max(sum(a for i, a in enumerate(A) if i in us) + sum(b for b, c in combo if len(c & set(us)) >= 3) for us in itertools.combinations(range(N), 9)))
