def calc(N):
    for s in reversed(S):
        if s == '-':
            N = -N
        elif s == '!':
            N = int(not N)
    return N


def calc2(N):
    for s in reversed(ans):
        if s == '-':
            N = -N
        elif s == '!':
            N = int(not N)
    return N

S = input()
ans = ''
if '!' not in S:
    ans = '-' * (len(S) & 1)
else:
    zero, non_zero = 0, 1
    for s in reversed(S):
        if s == '-':
            zero, non_zero = -zero, -non_zero
        elif s == '!':
            zero, non_zero = int(not zero), int(not non_zero)
    if zero == 0:
        ans = '!!' if non_zero > 0 else '-!!'
    else:
        ans = '!' if zero > 0 else '-!'
for i in range(-256, 257):
    assert(calc(i) == calc2(i))
print(ans)
