import itertools
import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input

while True:
    N = int(input())
    if not N:
        break
    strings = [input() for _ in range(N)]
    chars = list(set(''.join(strings)))
    ans = 0
    for nums in itertools.permutations(range(10), len(chars)):
        eq = strings[:]
        for c, i in zip(chars, nums):
            eq = [string.replace(c, str(i)) for string in eq]
        if all(len(string) == 1 or string[0] != '0' for string in eq) and sum(map(int, eq)) == int(eq[-1]) * 2:
            ans += 1
    print(ans)
