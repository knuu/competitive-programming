import math


class FenwickTree:
    def __init__(self, a_list):
        # 0-indexed
        self.N = len(a_list)
        self.bit = a_list[:]
        for _ in range(self.N, 1 << (math.ceil(math.log(self.N, 2)))):
            self.bit.append(0)
        for i in range(self.N-1):
            self.bit[i | (i+1)] += self.bit[i]

    def add(self, i, val):
        while i < self.N:
            self.bit[i] += val
            i |= i + 1

    def sum(self, n):
        """[0, n)"""
        ret = 0
        n -= 1
        while n >= 0:
            ret += self.bit[n]
            n = (n & (n + 1)) - 1
        return ret

    def index(self, k):
        return self.sum(k + 1) - self.sum(k)

    def count_index(self, k):
        left, right = -1, self.N - 1
        while left + 1 < right:
            mid = (left + right) >> 1
            if self.sum(mid + 1) >= k:
                right = mid
            else:
                left = mid
        return right


def solve(Q, queries):
    numbers = []
    for i, (t, x) in enumerate(queries):
        if t == 1:
            numbers.append((x, i))
    numbers.sort()
    N = len(numbers)
    fwt = FenwickTree([0] * N)
    idx2fwt = [0] * Q
    for idx, (_, i) in enumerate(numbers):
        idx2fwt[i] = idx
    for i, (t, x) in enumerate(queries):
        print([fwt.index(i) for i in range(N)])
        if t == 1:
            fwt.add(idx2fwt[i], 1)
        elif t == 2:
            idx = fwt.count_index(x)
            print(numbers[idx][0])
            fwt.add(idx, -1)


if __name__ == '__main__':
    Q = int(input())
    queries = [tuple(map(int, input().split())) for _ in range(Q)]
    solve(Q, queries)
