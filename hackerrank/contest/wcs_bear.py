from math import sqrt
range = xrange; input = raw_input

def count_divisors(n):
    cnt = 0
    for i in xrange(1, int(sqrt(n)+1)):
        if n % i == 0:
            cnt += 1
            if n // i != i:
                cnt += 1
    return cnt


memo = dict()
for _ in range(int(input())):
    N, K = map(int, input().split())
    while N > 0:
        if N in memo:
            ret = memo[N]
        else:
            ret = count_divisors(N)
            memo[N] = ret
        if ret == K:
            print(N)
            break
        else:
            N -= 1
    else:
        print(-1)
