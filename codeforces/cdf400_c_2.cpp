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

/*
Range Sum Query by FenwickTree(Binary Indexed Tree)

total number: n
queries:
    1. add(i, val): bit[i] += val
    2. sum(n): sum(bit[0] + ... + bit[n-1])
time complexity: O(log n)
space complexity: O(N)

Self-balancing binary search tree or Segment Tree can do the same, it takes longer to program and complexity also increases.

Thanks: http://hos.ac/slides/20140319_bit.pdf

used in ARC031 C, indeednow finalB E, DSL2B(AOJ), ARC033 C, yukicoder No.59
*/

template<typename T> struct RangeSumQuery {
  int N;
  vector<T> dat;

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
    return sum(k+1) - sum(k);
  }
};


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; ll K; cin >> N >> K;
  assert(K != 0);
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> acc(N + 1, 0); REP(i, N) acc[i + 1] += acc[i] + A[i];
  vector<pair<ll, int>> pos(N + 1); REP(i, N + 1) pos[i] = make_pair(acc[i], i);
  sort(ALL(pos));
  vector<int> pos2idx(N + 1);
  REP(i, N + 1) pos2idx[pos[i].second] = i;

  RangeSumQuery<ll> fwt(N + 1);
  REP(i, N + 1) fwt.add(i, 1);

  ll ans = 0;

  vector<ll> cand;
  if (K == 1) {
    cand.push_back(1);
  } else if (K == -1) {
    cand.push_back(1);
    cand.push_back(-1);
  } else {
    for (ll now = 1; abs(now) < (ll)1e18; now *= K) {
      cand.push_back(now);
    }
  }

  REP(i, N) {
    for (ll x : cand) {
      int lb = lower_bound(ALL(pos), make_pair(acc[i] + x, 0)) - pos.begin();
      if (lb != N + 1) {
        ll val = pos[lb].first;
        if (val - acc[i] == x) {
          int ub = lower_bound(ALL(pos), make_pair(acc[i] + x + 1, 0)) - pos.begin();
          ans += fwt.sum(lb, ub);
        }
      }
    }
    fwt.add(pos2idx[i], -1);
  }
  cout << ans << endl;
  return 0;
}
