import string
from itertools import combinations
N = int(input())
S = input()

ans = 0
for x, y in combinations(string.ascii_lowercase, 2):
    extracted = []
    for s in S:
        if s in [x, y]:
            extracted.append(s)
    if len(extracted) < 2 or all(extracted[0] == x for x in extracted):
        continue
    odd, even = extracted[::2], extracted[1::2]
    assert(len(odd) and len(even))
    if all(odd[0] == x for x in odd) and all(even[0] == x for x in even):
        ans = max(ans, len(extracted))
print(ans)
