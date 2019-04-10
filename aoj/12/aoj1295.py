from collections import Counter
import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input
while True:
    W, D = map(int, input().split())
    if not (W | D):
        break
    hw = [int(x) for x in input().split()]
    hd = [int(x) for x in input().split()]
    print(sum(hw) + sum(hd) - sum(k * v for k, v in (Counter(hw) & Counter(hd)).items()))
