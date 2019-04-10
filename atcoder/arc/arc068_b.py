from collections import Counter
N = int(input())
ans = 0
even = 0
cnt = Counter(map(int, input().split()))
for k, v in cnt.items():
    if v % 2 == 0:
        ans += (v - 2) // 2
        even += 1
    else:
        ans += v // 2
ans += even // 2 + even % 2
print(N - ans * 2)
