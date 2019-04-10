from collections import Counter
N = int(input())
A = Counter(map(int, input().split()))
ans = 0
for k, v in A.items():
    if k <= v:
        ans += v - k
    else:
        ans += v
print(ans)
