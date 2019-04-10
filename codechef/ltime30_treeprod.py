import sys
sys.setrecursionlimit(10000)
range = xrange; input = raw_input


def miller_rabin(n):
    """ primality Test
        if n < 3,825,123,056,546,413,051, it is enough to test
        a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.
        Complexity: O(log^3 n)
    """
    assert(n >= 1)
    if n == 2:
        return True
    if n <= 1 or not n & 1:
        return False

    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]

    d = n - 1
    s = 0
    while not d & 1:
        d >>= 1
        s += 1

    for prime in primes:
        if prime >= n:
            continue
        x = pow(prime, d, n)
        if x == 1:
            continue
        for r in range(s):
            if x == n - 1:
                break
            if r + 1 == s:
                return False
            x = x * x % n
    return True


def dfs(v, p, r, prd, mod):
    ret = 0
    if v > r and prd == 0:
        ret += 1
    for cv, cc in edge[v]:
        if cv != p:
            ret += dfs(cv, v, r, (prd * cc) % mod, mod)
    return ret


def dfs2(v, p, col):
    ret = 1
    color[v] = col
    for c in edge[v]:
        if c != p and not color[c]:
            ret += dfs2(c, v, col)
    return ret
    
N, M = map(int, input().split())
edge = [[] for _ in range(N)]
if N <= 1000:
    for i in range(N-1):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1
        edge[a].append((b, c % M))
        edge[b].append((a, c % M))

    ans = 0
    for i in range(N):
        ans += dfs(i, -1, i, 1, M)
    print(ans)
elif miller_rabin(M):
    for i in range(N-1):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1
        if c % M:
            edge[a].append(b)
            edge[b].append(a)
    ans = N * (N - 1) // 2
    color = [0] * N
    cnt = 0
    for i in range(N):
        if not color[i]:
            cnt += 1
            c = dfs2(i, -1, cnt)
            ans -= c * (c - 1) // 2
    print(ans)
else:
    raise Exception
