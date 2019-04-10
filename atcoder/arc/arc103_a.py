from collections import Counter

N = int(input())
V = [int(x) for x in input().split()]
if all(v == V[0] for v in V):
    print(N // 2)
    quit()
even = Counter([v for i, v in enumerate(V) if i % 2 == 0])
odd = Counter([v for i, v in enumerate(V) if i % 2 != 0])
evens = even.most_common()
odds = odd.most_common()
if evens[0][0] != odds[0][0]:
    print(N - evens[0][1] - odds[0][1])
elif len(evens) == len(odds) == 1:
    print(N // 2)
elif len(evens) == 1:
    print(min(N - odds[0][1], N - len(evens) - odds[1][1]))
elif len(odds) == 1:
    print(min(N - evens[0][1], N - len(odds) - evens[1][1]))
else:
    print(min(N - evens[0][1] - odds[1][1], N - evens[1][1] - odds[0][1]))
