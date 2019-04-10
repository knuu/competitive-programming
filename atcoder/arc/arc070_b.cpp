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

  int N, K; cin >> N >> K;
  vector<int> A(N); REP(i, N) cin >> A[i];

  RangeSumQuery<int> dp_left(K + 1);
  vector<bool> dp_right(K + 1);
  vector<int> prev(K + 1, -1);
  dp_right[0] = true;
  for (int i = N - 1; i >= 0; i--) {
    for (int j = K; j >= 0; j--) {
      //cout << i << ' ' << j << endl;
      if (j - A[i] >= 0 and dp_right[j - A[i]] and not dp_right[j]) {
        dp_right[j] = true;
        prev[j] = i;
      }
    }
  }
  dp_left.add(0, 1);

  int ans = 0;
  REP(i, N) {
    bool flag = true;
    for (int j = K; j >= 0; j--) {
      if (prev[j] == i) dp_right[j] = false;
      if (dp_right[j] and dp_left.sum(max(0, K - A[i] - j), K - j) > 0) {
        flag = false;
      }
    }
    if (flag) ans++;
    for (int j = K; j >= 0; j--) {
      if (j - A[i] >= 0 and dp_left.index(j - A[i]) == 1 and dp_left.index(j) == 0) {
        dp_left.add(j, 1);
      }
    }
    //for (auto x : dp_right) cout << x << ' ';
    //cout << endl;
    //REP(i, K + 1) cout << dp_left.index(i) << ' ';
    //cout << endl;
  }
  cout << ans << endl;





  return 0;
}
