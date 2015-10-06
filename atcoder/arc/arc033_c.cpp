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
const int MAX_N = 1 << 20;

/*
Range Sum Query by FenwickTree(Binary Indexed Tree)

queries:
    1. update(i, val): add val to i-th value 
    2. sum(n): sum(bit[0] + ... + bit[n-1])
time complexity: O(log n)
space complexity: O(N)

Segment Tree can do the same, it takes longer to program and complexity also increases.

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

  int sum(int k) {
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

  RangeSumQuery fwt(200001);

  int Q;
  cin >> Q;
  REP(i, Q) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      fwt.update(x, 1);
    } else {
      int left = 0, right = 200000;
      while (left + 1 < right) {
	int mid = (left + right) / 2;
	if (fwt.sum(mid+1) >= x) {
	  right = mid;
	} else {
	  left = mid;
	}
      }
      fwt.update(right, -1);
      cout << right << endl;
    }
  }
  return 0;
}

