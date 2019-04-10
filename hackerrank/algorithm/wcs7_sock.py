from collections import Counter
N = int(input())
print(sum(v // 2 for v in Counter(input().split()).values()))
