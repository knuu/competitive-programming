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

/**
 * @brief ange Sum Query by FenwickTree(Binary Indexed Tree)
 *
 * total number: n
 * queries:
 *    1. add(i, val): bit[i] += val
 *    2. sum(n): sum(bit[0] + ... + bit[n-1])
 * query time complexity: O(log n)
 * space complexity: O(N)
 *
 * Self-balancing binary search tree or Segment Tree can do the same, it takes
 * longer to program and complexity also increases.

 * Thanks: http://hos.ac/slides/20140319_bit.pdf
 * used in ARC031 C, indeednow finalB E, DSL2B(AOJ), ARC033 C, yukicoder No.59
 */

template <typename T>
struct RangeSumQuery {
  int N;
  std::vector<T> dat;

  RangeSumQuery(int N) : N(N) {
    assert(N > 0);
    dat.resize(N, 0);
  }

  void add(int k, T val) {
    assert(0 <= k && k < N);
    for (int x = k; x < N; x |= x + 1) {
      dat[x] += val;
    }
  }

  // [0, k)
  T sum(int k) {
    assert(k >= 0);
    T ret = 0;
    for (int x = k - 1; x >= 0; x = (x & (x + 1)) - 1) {
      ret += dat[x];
    }
    return ret;
  }
  // [l, r)
  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= N);
    return sum(r) - sum(l);
  }

  T index(int k) {
    assert(0 <= k && k < N);
    return sum(k + 1) - sum(k);
  }
};


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; ll W, C; cin >> N >> W >> C;
  vector<pair<ll, ll>> rocks(N);
  vector<ll> P(N);
  vector<pair<ll, int>> fo_idx(N), ba_idx(N);
  map<pair<ll, int>, vector<ll>> mp;
  REP(i, N) {
    ll l, r; cin >> l >> r >> P[i];
    mp[make_pair(l, 0)].emplace_back(i);
    mp[make_pair(r, -1)].emplace_back(i);
    fo_idx[i] = make_pair(l, i);
    ba_idx[i] = make_pair(W - r, i);
    rocks[i] = make_pair(l, r);
  }
  sort(ALL(fo_idx));
  sort(ALL(ba_idx));

  vector<int> fo(N+2), ba(N+2);
  RangeSumQuery<ll> fwt_f(N+2), fwt_b(N+2);
  fo[0] = ba[0] = -1;
  fo[N+1] = ba[N+1] = W + 1;
  REP(i, N) {
    ll l; int idx; tie(l, idx) = fo_idx[i];
    fo[i+1] = l;
    fwt_f.add(i+1, P[idx]);
    ll r; tie(r, idx) = ba_idx[i];
    ba[i+1] = r;
    fwt_b.add(i+1, P[idx]);
  }

  // from zero and from W
  int f_idx = lower_bound(ALL(fo), C) - fo.begin();
  int b_idx = lower_bound(ALL(ba), C) - ba.begin();
  ll ans = min(fwt_f.sum(f_idx), fwt_b.sum(b_idx));

  ll left_sum = 0;
  for (auto&& p : mp) {
    ll pos; int ty; tie(pos, ty) = p.first;
    if (ty == -1) for (auto&& idx : p.second) left_sum -= P[idx];

    if (ty == 0 and pos + C <= W) {
      ll left = pos, right = pos + C;
      int l_idx = lower_bound(ALL(fo), left) - fo.begin();
      int r_idx = lower_bound(ALL(fo), right) - fo.begin();
      ans = min(ans, fwt_f.sum(r_idx) - fwt_f.sum(l_idx) + left_sum);
    } else if (ty == -1 and pos + C <= W) {
      ll left = pos, right = pos + C;
      int l_idx = lower_bound(ALL(fo), left) - fo.begin();
      int r_idx = lower_bound(ALL(fo), right) - fo.begin();
      ans = min(ans, fwt_f.sum(r_idx) - fwt_f.sum(l_idx) + left_sum);
    }

    if (ty == 0) for (auto&& idx : p.second) left_sum += P[idx];
  }

  ll right_sum = 0;

  for (auto itr = std::rbegin(mp); itr != std::rend(mp); ++itr) {
    ll pos; int ty; tie(pos, ty) = itr->first;
    if (ty == 0) for (auto&& idx : itr->second) right_sum -= P[idx];

    if (ty == 0 and pos - C >= 0) {
      ll left = W - pos, right = W - (pos - C);
      int l_idx = lower_bound(ALL(ba), left) - ba.begin();
      int r_idx = lower_bound(ALL(ba), right) - ba.begin();
      ans = min(ans, fwt_b.sum(r_idx) - fwt_b.sum(l_idx) + right_sum);
    } else if (ty == -1 and pos - C >= 0) {
      ll left = W - pos, right = W - (pos - C);
      int l_idx = lower_bound(ALL(ba), left) - ba.begin();
      int r_idx = lower_bound(ALL(ba), right) - ba.begin();
      ans = min(ans, fwt_b.sum(r_idx) - fwt_b.sum(l_idx) + right_sum);
    }

    if (ty == -1) for (auto&& idx : itr->second) right_sum += P[idx];
  }

  cout << ans << endl;
  return 0;
}
