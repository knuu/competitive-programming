import itertools
N = int(input())
A = [int(x) for x in input().split()]
max_A = max(A)
counter = [[] for _ in range(max_A + 1)]
for i, a in enumerate(A):
    counter[a].append(i)
if any(len(counter[i]) > 3 for i in range(max_A + 1)):
    print(0)
    quit()
if any(len(counter[i]) < len(counter[i+1]) for i in range(max_A)):
    print(0)
    quit()

ans = [3, 6, 6][len(counter[0])-1]
mod = 10 ** 9 + 7
for i in range(max_A):
    cnt = 0
    for li in itertools.permutations(counter[i], len(counter[i+1])):
        cnt += all(v1 < v2 for v1, v2 in zip(li, counter[i+1]))
    ans = (ans * cnt) % mod
print(ans)
