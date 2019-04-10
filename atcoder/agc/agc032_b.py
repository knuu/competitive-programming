from copy import deepcopy
from functools import reduce


class Divisor:
    def __init__(self, n):
        """ make divisors list and prime factorization list of n
            complexity: O(n^(1/2))
            used in ProjectEuler No.12, yukicoder No.36
        """
        assert(n >= 1)
        number = n
        if number == 1:
            self.primeFactorization = {1: 1}
        else:
            self.primeFactorization = {}
            for i in range(2, int(n**0.5)+1):
                cnt = 0
                while number % i == 0:
                    cnt += 1
                    number //= i
                if cnt > 0:
                    self.primeFactorization[i] = cnt
            if number > 1:
                self.primeFactorization[number] = 1

    def primeFactors(self):
        return deepcopy(self.primeFactorization)

    def numDivisors(self):
        """ the number of divisors """
        if self.primeFactorization.get(1, 0) == 1:
            return 1
        numDiv = 1
        for _, cnt in self.primeFactorization.items():
            numDiv *= cnt+1
        return numDiv

    def sumDivisors(self):
        return reduce(lambda x, y: x * y, [sum(p**i for i in range(n+1)) for p, n in self.primeFactorization.items()])


def divisorsList(n):
    assert(n >= 1)
    divsList = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divsList.append(i)
            if n // i != i:
                divsList.append(n//i)
    return sorted(divsList)


def subsum(arr, M):
    dp = [0] * (M + 1)
    prev = [-1] * (M + 1)
    dp[0] = 1
    for x in reversed(arr):
        for i in reversed(range(M + 1)):
            if dp[i] and i + x <= M and not dp[i + x]:
                dp[i + x] = 1
                prev[i + x] = i
    assert dp[-1]
    ans = []
    now = M
    while prev[now] != -1:
        ans.append(now - prev[now])
        now = prev[now]
    return ans


def dfs(groups, i, now):
    if i == len(groups):
        print(*now)
        return
    for x in groups[i]:
        now.append(x)
        dfs(groups, i + 1, now)
        now.pop()


def main(N):
    sumall = N * (N + 1) // 2
    group_num = divisorsList(sumall)[1]
    groups = []
    selected = set()
    rest = list(range(1, N + 1))
    for i in range(group_num):
        g = subsum(rest, sumall // group_num)
        groups.append(g)
        selected |= set(g)
        rest = [x for x in rest if x not in selected]
    edges = []
    for i in range(len(groups)):
        for j in range(len(groups)):
            if i >= j:
                continue
            for x1 in groups[i]:
                for x2 in groups[j]:
                    edges.append((x1, x2))
    print(len(edges))
    for e in edges:
        print(*e)


if __name__ == '__main__':
    N = int(input())
    main(N)
