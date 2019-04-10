from collections import Counter
N = int(input())
A = []
for a in map(int, input().split()):
    A.append(a)
    A.append(a + 1)
    A.append(a - 1)
print(Counter(A).most_common(1)[0][1])
