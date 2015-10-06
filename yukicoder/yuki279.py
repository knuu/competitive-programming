from collections import Counter
c = Counter(input())
print(min(c['t'], c['r'], c['e']//2))
