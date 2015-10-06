#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

#define INF 2147483647
const int MAX_N = 1000000;

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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  RangeSumQuery fwt(1000001);

  REP(i, N) {
    int W;
    cin >> W;
    if (W < 0) {
      W = abs(W);
      if (fwt.query(W+1) - fwt.query(W) > 0) {
	fwt.update(W, -1);
      }
    } else {
      if (fwt.query(1000001) - fwt.query(W) < K) {
	fwt.update(W, 1);
      }
    }
  }
  cout << fwt.query(1000001) << endl;
  
  return 0;
}
