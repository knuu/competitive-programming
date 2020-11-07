from collections import Counter
input()
c1 = Counter(map(int, input().split()))
input()
c2 = Counter(map(int, input().split()))
print("YES" if all(c1[k] >= v for k, v in c2.items()) else "NO")
