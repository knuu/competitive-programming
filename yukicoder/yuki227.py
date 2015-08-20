from collections import Counter
c = Counter(map(int, input().split()))
m = c.most_common()

if len(c) == 2 and m[0][1] == 3:
    print('FULL HOUSE')
elif len(c) == 3 and m[0][1] == 3:
    print('THREE CARD')
elif len(c) == 3 and m[0][1] == m[1][1]:
    print('TWO PAIR')
elif len(c) == 4:
    print('ONE PAIR')
else:
    print('NO HAND')
