import math
class FenwickTree:
    """
    FenwickTree(Binary Indexed Tree)
    total number: n
    queries:
    1. add(i, val): add val to i-th value 
    2. sum(n): sum(bit[0] + ... + bit[n-1])
    complexity: O(log n)

    Self-balancing binary search tree or Segment Tree can do the same, it takes longer to program and complexity also increases.
    Thanks: http://hos.ac/slides/20140319_bit.pdf
    
    used in ARC031 C, indeednow finalB E
    """
    def __init__(self, a_list):
        # 0-indexed
        self.N = len(a_list)
        self.bit = a_list[:]
        for _ in range(N, 1<<(math.ceil(math.log(N, 2)))): self.bit.append(0)
        for i in range(self.N-1):
            self.bit[i | (i+1)] += self.bit[i]

    def add(self, i, val):
        while i < self.N:
            self.bit[i] += val
            i |= i + 1

    def sum(self, n):
        ret = 0
        while n >= 0:
            ret += self.bit[n]
            n = (n & (n + 1)) - 1
        return ret

N, Q = map(int, input().split())
bit = FenwickTree([0]*N)
for _ in range(Q):
    com, x, y = map(int, input().split())
    if com == 0:
        bit.add(x-1, y)
    elif com == 1:
        print(bit.sum(y-1) - bit.sum(x-2))
