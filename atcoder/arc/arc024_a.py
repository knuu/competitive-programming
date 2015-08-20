from collections import *
_ = input()
c1 = Counter(map(int, input().split()))
c2 = Counter(map(int, input().split()))
print(sum((c1 & c2).values()))
