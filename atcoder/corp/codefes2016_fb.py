from math import ceil
N = int(input())
ans = int(ceil((-1 + (1 + 4 * 2 * N) ** 0.5) / 2))
for i in reversed(range(1, ans+1)):
    if i <= N:
        print(i)
        N -= i
assert(not N)
