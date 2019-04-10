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

template<typename T> struct RangeMaxQuery {
  int N, _N;
  vector<T> dat;

  RangeMaxQuery(int _N) : _N(_N) {
    assert(_N > 0);
    N = 1;
    while (N < _N)
      N <<= 1;
    dat.assign(2 * N - 1, 0);
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
    if (r <= a || b <= l) return 0;
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
  cout << setprecision(20);

  ll sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy;
  if (sx > gx) swap(sx, gx), swap(sy, gy);
  bool flag = false;
  if (sy > gy) {
    gy += 2 * (sy - gy);
    flag = true;
  }
  assert(sx <= gx and sy <= gy);

  int N; cin >> N;
  vector<pair<ll, ll>> jet;
  REP(i, N) {
    ll x, y; cin >> x >> y;
    if (flag) y += 2 * (sy - y);
    if (sx <= x and x <= gx and sy <= y and y <= gy) jet.emplace_back(x, y);
  }
  N = jet.size();

  double ans = 100 * (1.0 * (gx - sx) + 1.0 * (gy - sy));

  if (N == 0) {
    cout << ans << endl;
    return 0;
  }

  vector<pair<ll, int>> X, Y;
  REP(i, N) {
    int x, y; tie(x, y) = jet[i];
    X.emplace_back(x, i);
    Y.emplace_back(y, i);
  }
  sort(ALL(X)), sort(ALL(Y));

  vector<int> segt_idx(N);
  REP(i, N) segt_idx[X[i].second] = i;

  RangeMaxQuery<int> dp(N);
  for (int i = N - 1; i >= 0; i--) {
    int idx = Y[i].second;
    int left = lower_bound(ALL(X), make_pair(jet[idx].first + 1, 0)) - X.begin();
    dp.update(segt_idx[idx], dp.query(left, N) + 1);
  }

  if (dp.query(0, N) == min(gx - sx, gy - sy) + 1) {
    cout << ans + (20 * acos(-1) / 4 - 20) * (dp.query(0, N) - 1) + (20 * acos(-1) / 2 - 20) << endl;
  } else {
    cout << ans + (20 * acos(-1) / 4 - 20) * dp.query(0, N) << endl;
  }
  //cout << dp.query(0, N) << endl;
  return 0;
}
