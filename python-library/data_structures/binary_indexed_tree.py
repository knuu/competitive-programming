# http://hos.ac/slides/20140319_bit.pdf
# used in ARC031 C, indeednow finalB E
"""
Binary Indexed Tree
total number: n
queries:
1. update
2. a sum interval 
complexity: O(log n)

Self-balancing binary search tree or Segment Tree can do the same, it takes longer to program and complexity also increases.
"""


n = 100 # length of BIT

bit = [0 for _ in range(n+10)] # initialization by 0
bit = [x & -x for x in range(n+10)] # initialization by 1

# initialization by a list bit
def init():
    x = 1
    while x < N:
        bit[x + (x & -x)] += bit[x]
        x += 1

# update the value (bit[update] = value)
def add(update, value):
    x = update
    while x <= update:
        bit[x] += value
        x += x & -x

# sum(bit[1] + ... + bit[update])
def sum(update):
    ret = 0
    x = update
    while x > 0:
        ret += bit[x]
        x -= x & -x
    return ret

#### 0-indexed
bit = [(x+1) & -(x+1) for x in range(n+10)] # initialization by 1
# initialization by a list bit
def init():
    x = 0
    while x < N - 1:
        bit[x | (x + 1)] += bit[x]
        x += 1

# update the value (bit[update] = value)
def add(update, value):
    x = update
    while x < update:
        bit[x] += value
        x |= x + 1

# sum(bit[1] + ... + bit[update])
def sum(update):
    ret = 0
    x = update - 1
    while x >= 0:
        ret += bit[x]
        x = (x & (x + 1)) - 1
    return ret

