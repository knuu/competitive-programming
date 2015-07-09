class FenwickTree:
    """
    FenwickTree(Binary Indexed Tree)
    total number: n
    queries:
    1. update
    2. a sum interval 
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

    def add(self, update, value):
        while update < self.N:
            self.bit[update] += value
            update |= update + 1

    def sum(self, update):
        # sum(bit[1] + ... + bit[update])
        ret = 0
        while update >= 0:
            ret += self.bit[update]
            update = (update & (update + 1)) - 1
        return ret

N = int(input())
B = [int(x) for x in input().split()]

blocks = sorted((x, i) for i, x in enumerate(B))
bit = FenwickTree([1]*N)

ans = 0
for _, i in blocks:
    bit.add(i, -1)
    sumN, sumi = bit.sum(N-1), bit.sum(i)
    ans += min(sumN-sumi, sumi)
print(ans)
