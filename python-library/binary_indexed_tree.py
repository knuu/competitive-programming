# http://hos.ac/slides/20140319_bit.pdf
"""
変数: n個
クエリ:
1. 値を加える(更新)
2. 区間和を求める
計算時間: O(log n)

平衡二分探索木やSegment Treeでもできるが、実装量と計算量が数倍
"""


n = 100 # 入力数

bit = [0 for _ in range(n+10)] # binary indexed treeの初期化
bit = [x & -x for x in range(n+10)] # 1で初期化する場合

# それぞれで初期化したい場合、普通に配列に入れておいて以下のように更新する
def init():
    x = 1
    while x < N:
        bit[x + (x & -x)] += bit[x]
        x += 1

# 値の更新(bit[update] = value)
def add(update, value):
    x = update
    while x <= n:
        bit[x] += value
        x += x & -x

# 和の計算(bit[1] + ... + bit[update])
def sum(update):
    ret = 0
    x = update
    while x > 0:
        ret += bit[x]
        x -= x & -x
    return ret

#### 0ベースだと以下
bit = [(x+1) & -(x+1) for x in range(n+10)] # 1で初期化する場合
# それぞれで初期化したい場合、普通に配列に入れておいて以下のように更新する
def init():
    x = 0
    while x < N - 1:
        bit[x | (x + 1)] += bit[x]
        x += 1

# 値の更新(bit[update] = value)
def add(update, value):
    x = update
    while x < n:
        bit[x] += value
        x |= x + 1

# 和の計算(bit[0] + ... + bit[update - 1] , update個の和)
def sum(update):
    ret = 0
    x = update - 1
    while x >= 0:
        ret += bit[x]
        x = (x & (x + 1)) - 1
    return ret

