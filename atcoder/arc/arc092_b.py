import bisect
import sys
if sys.version[0] == "2":
    range, input = xrange, raw_input

N = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

bits = [1 << i for i in range(31)]
ans = 0
for i in range(30):
    mod = bits[i + 1] - 1
    mod_A = [a & mod for a in A]
    mod_B = [b & mod for b in B]
    mod_A.sort()
    bit_count = 0
    for b in mod_B:
        bit_count += bisect.bisect_left(mod_A, bits[i + 1] - b) - bisect.bisect_left(mod_A, bits[i] - b)
        bit_count += N - bisect.bisect_left(mod_A, (bits[i + 1] | bits[i]) - b)
    if bit_count & 1:
        ans |= bits[i]
print(ans)
