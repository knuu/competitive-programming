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
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

template<class Monoid>
struct SegmentTree {
  using T = typename Monoid::type;
  int N_, N;
  std::vector<T> dat;

  SegmentTree(const int N_) : N_(N_) {
    assert(N_ > 0);
    N = 1;
    while (N < N_) {
      N <<= 1;
    }
    dat.assign(2 * N - 1, Monoid::identity());
  }

  SegmentTree(const std::vector<T> &dat_) : N_(dat_.size()) {
    assert(N_ > 0);
    N = 1;
    while (N < N_) {
      N <<= 1;
    }
    dat.assign(2 * N - 1, Monoid::identity());
    std::copy(dat_.begin(), dat_.end(), dat.begin() + N - 1);
    for (int i = N - 2; i >= 0; i--) {
      dat[i] = Monoid::merge(dat[2 * i + 1], dat[2 * i + 2]);
    }
  }

  int size() { return N_; }

  void update(int key, T val) {
    assert(0 <= key && key < N_);

    key += N - 1;
    dat[key] = val;

    while (key > 0) {
      key = (key - 1) / 2;
      dat[key] = Monoid::merge(dat[2 * key + 1], dat[2 * key + 2]);  // rewrite here
    }
  }

  // [a, b)
  T query(int low, int high) {
    assert(0 <= low && low <= high && high <= N_);
    return query(low, high, 0, 0, N);
  }

  T query(int low, int high, int key, int left, int right) {
    if (right <= low || high <= left) return Monoid::identity();
    if (low <= left && right <= high) return dat[key];

    int mid = (left + right) / 2;
    return Monoid::merge(query(low, high, 2 * key + 1, left, mid),
                         query(low, high, 2 * key + 2, mid, right));  // rewrite here
  }
};

template <typename T>
struct RangeSumQuery {
  using type = T;
  static type identity() { return 0; }
  static type merge(const type &l, const type &r) {
    return l + r;
  }
};

template <typename T>
struct RangeMinQuery {
  using type = T;
  static type identity() { return INT_MAX; }
  static type merge(const type &l, const type &r) {
    return min(l, r);
  }
};

template <typename T>
struct RangeMaxQuery {
  using type = T;
  static type identity() { return 0; }
  static type merge(const type &l, const type &r) {
    return max(l, r);
  }
};


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; ll W, C; cin >> N >> W >> C;
  vector<pair<ll, ll>> rocks(N);
  vector<ll> P(N);
  vector<tuple<ll, int, int>> indices;
  REP(i, N) {
    ll l, r; cin >> l >> r >> P[i];
    indices.emplace_back(l, i, 0);
    indices.emplace_back(r, i, -1);
    rocks[i] = make_pair(l, r);
  }
  indices.emplace_back(-1, -2, -1);
  indices.emplace_back(W+1, 1, -1);
  sort(ALL(indices));
  assert(indices.size() == 2 * N + 2);
  /*
  REP(i, 2 * N + 2) {
    ll p; int ty, idx; tie(p, ty, idx) = indices[i];
    cout << '(' << p << ',' << ty << ',' << idx << "),";
  }
  cout << endl;
  */
  vector<ll> imos(2 * N + 2);
  REP(i, 2*N) {
    ll pos; int idx, ty; tie(pos, idx, ty) = indices[i+1];
    //cout << '(' << pos << ',' << ty << ',' << idx << ',' << P[idx] << "),";
    if (ty == 0) {
      imos[i+1] += P[idx];
    } else if (ty == -1) {
      imos[i+1] -= P[idx];
    }
  }
  for (ll x : imos) cout << x << ' ';
  cout << endl;
  SegmentTree<RangeMaxQuery<ll>> rmq(2*N + 2);
  REP(i, 2*N + 1) {
    imos[i+1] += imos[i];
    rmq.update(i+1, imos[i+1]);
  }
  for (ll x : imos) cout << x << ' ';
  cout << endl;

  // from zero and from W
  int f_idx = lower_bound(ALL(indices), make_tuple(C, 0, 0)) - indices.begin();
  int b_idx = lower_bound(ALL(indices), make_tuple(W-C, 0, 0)) - indices.begin();
  ll f_query = rmq.query(1, f_idx), b_query = rmq.query(b_idx, 2 * N + 2);
  cout << f_idx << ' ' << f_query << ' ' << b_idx << ' ' << b_query << endl;
  ll ans = min(f_query, b_query);
  /*
  REP(i, N) {
    ll l, r; tie(l, r) = rocks[i];
    if (l - C >= 0) {
      ll left = W - l, right = W - (l - C);
      int l_idx = lower_bound(ALL(ba), left) - ba.begin();
      int r_idx = lower_bound(ALL(ba), right) - ba.begin();
      ans = min(ans, fwt_b.sum(r_idx) - fwt_b.sum(l_idx));
    } else if (l + C <= W) {
      ll left = l, right = l + C;
      int l_idx = lower_bound(ALL(fo), left) - fo.begin();
      int r_idx = lower_bound(ALL(fo), right) - fo.begin();
      ans = min(ans, fwt_f.sum(r_idx) - fwt_f.sum(l_idx));
    } else if (r - C >= 0) {
      ll left = W - r, right = W - (r - C);
      int l_idx = lower_bound(ALL(ba), left) - ba.begin();
      int r_idx = lower_bound(ALL(ba), right) - ba.begin();
      ans = min(ans, fwt_b.sum(r_idx) - fwt_b.sum(l_idx));
    } else if (r + C <= W) {
      ll left = r, right = r + C;
      int l_idx = lower_bound(ALL(fo), left) - fo.begin();
      int r_idx = lower_bound(ALL(fo), right) - fo.begin();
      ans = min(ans, fwt_f.sum(r_idx) - fwt_f.sum(l_idx));
    }
    }*/

  cout << ans << endl;
  return 0;
}
