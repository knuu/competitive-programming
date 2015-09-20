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

#define INF 2147483647
const int MAX_N = 1 << 17;

int dat[2 * MAX_N - 1];

struct RangeMinimumQuery {
  int N;

  RangeMinimumQuery(int N_) {
    N = 1;
    while (N < N_)
      N <<= 1;
  
    for (int i = 0; i < 2 * N - 1; i++)
      dat[i] = INF;
  }

  // 0-indexed
  void update(int k, int val) {
    k += N - 1;
    dat[k] = val;

    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }  
  }

  // min [a, b)
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

int main() {
  ios_base::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  RangeMinimumQuery segtree(n);

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
