from collections import Counter
N, M = map(int, input().split())
cnt = Counter()
for _ in range(M):
    a, b = map(int, input().split())
    cnt[a] += 1
    cnt[b] += 1
print("YES" if all(x % 2 == 0 for x in cnt.values()) else "NO")
