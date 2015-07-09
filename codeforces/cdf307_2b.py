from collections import Counter
from copy import deepcopy

def getMax(c1, c2):
    ret = 1 << 32
    for k in c2.keys():
        ret = min(ret, c1[k]//c2[k])
    return ret

a, b, c = input(), input(), input()
counterA, counterB, counterC = Counter(a), Counter(b), Counter(c)

cntB, cntC = 0, getMax(counterA, counterC)
counterAA = deepcopy(counterA)
cntBB = 0
while counterAA & counterB == counterB:
    cntBB += 1
    counterAA -= counterB
    cntCC = getMax(counterAA, counterC)
    if cntB + cntC < cntBB + cntCC:
        cntB, cntC = cntBB, cntCC

ans = b * cntB + c * cntC
ans += ''.join((counterA - Counter(ans)).elements())
print(ans)
