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
struct RangeMinQuery {
  using type = T;
  static type identity() { return INT_MAX; }
  static type merge(const type &l, const type &r) {
    return min(l, r);
  }
};


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<int> A(N); REP(i, N) cin >> A[i];

  int ans = 0;
  SegmentTree<RangeMinQuery<int>> rmq(N);
  rmq.update(N-1, A[N-1]);
  for (int i = N-2; i >= 0; i--) {
    if (rmq.query(i, N) <= A[i]) {
      ans++;
    }
    rmq.update(i, A[i]);
  }
  cout << ans << endl;


  return 0;
}
