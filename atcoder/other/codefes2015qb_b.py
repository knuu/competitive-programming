from collections import Counter
N, M = map(int, input().split())
c = Counter(map(int, input().split()))
a = c.most_common()[0]
if a[1] > N / 2:
    print(a[0])
else:
    print('?')
