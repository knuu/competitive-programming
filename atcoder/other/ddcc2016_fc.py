import sys
sys.setrecursionlimit(10**5)
if sys.version[0] == '2':
    input, range = raw_input, xrange

A, B, C = map(int, input().split())
T = input()
assert(len(T) <= 10)

INF = 10**18
def dfs(s, prev):
    if s == T:
        return 0
    elif len(s) > len(T):
        return INF

    ret = INF
    ret = min(ret, dfs('0' + s, False) + A)
    ret = min(ret, dfs(s + '1', False) + B)
    if not prev:
        ret = min(ret, dfs(''.join('10'[int(x)] for x in s), True) + C)
    return ret

print(dfs('', False))
