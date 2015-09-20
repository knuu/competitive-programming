from itertools import cycle
print(sum(x*sig for x, sig in zip(map(int, list(input())), cycle([1, -1]))))
