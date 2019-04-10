#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
//typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

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
  int default_num;

  RangeMaxQuery(int _N, int default_num = 0) : _N(_N), default_num(default_num) {
    assert(_N >= 0);
    N = 1;
    while (N < _N)
      N <<= 1;
    dat.assign(2 * N - 1, default_num);
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
    if (r <= a || b <= l) return default_num;
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

  int N, C, D; cin >> N >> C >> D;
  vector<pair<int, int>> fC, fD;
  REP(i, N) {
    int b, p; string t; cin >> b >> p >> t;
    if (t == "C" and p <= C) {
      fC.emplace_back(p, b);
    } else if (t == "D" and p <= D) {
      fD.emplace_back(p, b);
    }
  }
  sort(ALL(fC)), sort(ALL(fD));
  RangeMaxQuery<int> seg_C(fC.size()), seg_D(fD.size());
  REP(i, fC.size()) {
    int b, p; tie(p, b) = fC[i];
    seg_C.update(i, b);
  }
  REP(i, fD.size()) {
    int b, p; tie(p, b) = fD[i];
    seg_D.update(i, b);
  }

  int ans = -1;
  if (fC.size() and fD.size()) ans = seg_C.query(0, fC.size()) + seg_D.query(0, fD.size());

  // cout << C << ' ' << D << endl;
  if (fC.size() > 1) {
    REP(i, fC.size()) {
      int b, p; tie(p, b) = fC[i];
      seg_C.update(i, 0);
      int idx = lower_bound(ALL(fC), make_pair(C - p, INF)) - fC.begin();
      //cout << b << ' ' << p << ':' << idx << endl;
      if (idx) ans = max(ans, b + seg_C.query(0, idx));
      seg_C.update(i, b);
    }
  }

  if (fD.size() > 1) {
    REP(i, fD.size()) {
      int b, p; tie(p, b) = fD[i];
      seg_D.update(i, 0);
      int idx = lower_bound(ALL(fD), make_pair(D - p, INF)) - fD.begin();
      //cout << b << ' ' << p << ':' << idx << endl;
      if (idx) ans = max(ans, b + seg_D.query(0, idx));
      seg_D.update(i, b);
    }
  }

  cout << (ans == -1 ? 0 : ans) << endl;

  return 0;
}
