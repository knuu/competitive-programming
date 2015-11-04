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
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

const int INF = 2147483647;

/*
RangeMinimumQuery by Segment Tree
query:
    1. update(i, val): update i-th value to val(0-indexrd)
    2. query(low, high): find minimun value in [low, high)
time complexity: O(log n)
space complexity: O(2n) 
used in DSL2A(AOJ)
*/
template<typename T> struct RangeMinQuery {
  int N, _N;
  vector<T> dat;

  RangeMinQuery(int _N) : _N(_N) {
    assert(_N > 0);
    N = 1;
    while (N < _N)
      N <<= 1;
    dat.resize(2 * N - 1, INF);
  }

  void update(int k, T val) {
    assert(0 <= k && k < _N);
    k += N - 1;
    dat[k] = val;

    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }  
  }

  // [a, b)
  T query(int a, int b) {
    assert(0 <= a && a <= b && b <= _N);
    return query(a, b, 0, 0, N);
  }
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return dat[k];

    int mid = (l + r) / 2;
    return min(query(a, b, 2 * k + 1, l, mid),
	       query(a, b, 2 * k + 2, mid, r));
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  RangeMinQuery<int> segtree(n);

  REP(i, q) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      segtree.update(x, y);
    } else if (com == 1) {
      cout << segtree.query(x, y+1) << endl;
    }
  }
  
  return 0;
}
