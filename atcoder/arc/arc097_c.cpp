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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<vector<int>> balls(2, vector<int>(N));
  REP(i, 2 * N) {
    char c; cin >> c;
    int x; cin >> x; x--;
    balls[c == 'B'][x] = i;
  }
  vector<vector<vector<int>>> cost(2, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));
  SegmentTree<RangeSumQuery<int>> rsq(2 * N);

  REP(k, 2) {
    for (int i = N - 1; i >= 0; i--) {
      int val = rsq.query(0, balls[k][i]);
      REP(j, N + 1) cost[k][k == 0 ? i + 1 : j][k == 0 ? j : i + 1] += val;
      rsq.update(balls[k][i], 1);
    }
    REP(i, N) rsq.update(balls[k][i], 0);
  }

  REP(k, 2) {
    REP(i, N) {
      REP(j, N) rsq.update(balls[k ^ 1][j], 1);
      REP(j, N + 1) {
        cost[k][k == 0 ? i + 1 : j][k == 0 ? j : i + 1] += rsq.query(0, balls[k][i]);
        if (j < N) rsq.update(balls[k ^ 1][j], 0);
      }
    }
  }

  vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
  REP(i, N + 1) REP(j, N + 1) {
    if (i == 0 and j > 0) {
      dp[i][j] = dp[i][j - 1] + cost[1][i][j];
    } else if (i > 0 and j == 0) {
      dp[i][j] = dp[i - 1][j] + cost[0][i][j];
    } else if (i > 0 and j > 0) {
      dp[i][j] = min(dp[i - 1][j] + cost[0][i][j], dp[i][j - 1] + cost[1][i][j]);
    }
  }

  cout << dp[N][N] << endl;
  return 0;


}
