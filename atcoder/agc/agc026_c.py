import sys

if sys.version[0] == '2':
    range, input = xrange, raw_input

from collections import defaultdict
N = int(input())
S = input()
first, second = S[:N], S[N:]

s_set = defaultdict(int)

def make_str(bit, s):
    red = []
    blue = []
    for i in range(N):
        if bit >> i & 1:
            red.append(s[i])
        else:
            blue.append(s[i])
    return ''.join(red), ''.join(blue[::-1])

for bit in range(1 << N):
    s_set[make_str(bit, second)] += 1

ans = 0
for bit in range(1 << N):
    red, blue = make_str(bit, first)
    ans += s_set[blue, red]
print(ans)
