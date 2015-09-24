#define INF 2147483647
const int MAX_N = 1 << 17;

int dat[2 * MAX_N - 1];

/*
RangeMinimumQuery by Segment Tree
query:
    1. update(i, val): update i-th value to val(0-indexrd)
    2. query(low, high): find minimun value in [low, high)
time complexity: O(log n)
space complexity: O(2n) 
used in DSL2A(AOJ)
*/
struct RangeMinimumQuery {
  int N;

  RangeMinimumQuery(int N_) {
    N = 1;
    while (N < N_)
      N <<= 1;
  
    for (int i = 0; i < 2 * N - 1; i++)
      dat[i] = INF;
  }

  void update(int k, int val) {
    k += N - 1;
    dat[k] = val;

    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }  
  }

  int query(int a, int b) {
    return query(a, b, 0, 0, N);
  }
  int query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return dat[k];

    int mid = (l + r) / 2;
    return min(query(a, b, 2 * k + 1, l, mid),
	       query(a, b, 2 * k + 2, mid, r));
  }
};
