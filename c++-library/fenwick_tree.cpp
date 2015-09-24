#define INF 2147483647
const int MAX_N = 1 << 17;

/*
Range Sum Query by FenwickTree(Binary Indexed Tree)

total number: n
queries:
    1. update(i, val): add val to i-th value 
    2. query(n): sum(bit[0] + ... + bit[n-1])
complexity: O(log n)

Self-balancing binary search tree or Segment Tree can do the same, it takes longer to program and complexity also increases.

Thanks: http://hos.ac/slides/20140319_bit.pdf
    
used in ARC031 C, indeednow finalB E, DSL2B(AOJ)
*/

int dat[MAX_N + 1];

struct RangeSumQuery {
  int N;

  RangeSumQuery(int N) : N(N) { }

  void update(int k, int val) {
    for (int x = k; x < N; x |= x + 1) {
      dat[x] += val;
    }
  }

  int query(int k) {
    int ret = 0;
    for (int x = k - 1; x >= 0; x = (x & (x + 1)) - 1) {
      ret += dat[x];
    }
    return ret;
  }
};
