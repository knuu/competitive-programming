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

int imos[100010];
P sec[100010];

const int INF = 1<<29;

/*
RangeMinimumQuery by Segment Tree
query:
    1. update(i, val): update i-th value to val(0-indexrd)
    2. query(low, high): find minimun value in [low, high)
time complexity: O(log n)
space complexity: O(2n) 
used in DSL2A(AOJ)
*/
template<typename T> struct RangeMaxQuery {
  int N, _N;
  vector<T> dat;

  RangeMaxQuery(int _N) : _N(_N) {
    assert(_N > 0);
    N = 1;
    while (N < _N)
      N <<= 1;
    dat.assign(2 * N - 1, -INF);
  }

  void update(int k, T val) {
    assert(0 <= k && k < _N);
    k += N - 1;
    dat[k] = val;

    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = max(dat[2 * k + 1], dat[2 * k + 2]);
    }  
  }

  // [a, b)
  T query(int a, int b) {
    assert(0 <= a && a <= b && b <= _N);
    return query(a, b, 0, 0, N);
  }
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return -INF;
    if (a <= l && r <= b) return dat[k];

    int mid = (l + r) / 2;
    return max(query(a, b, 2 * k + 1, l, mid),
	       query(a, b, 2 * k + 2, mid, r));
  }
};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  REP(i, N) {
    int s, t;
    cin >> s >> t; s--, t--;
    sec[i] = P(s, t);
    imos[s]++, imos[t]--;
  }
  REP(i, 100000) imos[i+1] += imos[i];
  RangeMaxQuery<int> sgt(100000);
  REP(i, 100000) sgt.update(i, imos[i]);
  //REP(i, 4) cout << sgt.query(i, i+1) << (i == 3 ? '\n' : ' ');
  //cout << sgt.query(0, 0) << endl;
  int ans = INF;
  REP(i, N) {
    int s = sec[i].first, t = sec[i].second;
    int cand = sgt.query(s, t) - 1;
    if (s > 0) cand = max(cand, sgt.query(0, s));
    if (t < 100000) cand = max(cand, sgt.query(t, 100000));
    ans = min(ans, cand);
  }
  cout << ans << endl;
  return 0;
}
