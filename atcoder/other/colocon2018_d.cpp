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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, X; cin >> N >> X;
  vector<int> T(N + 1);
  T[0] = -1e9;
  REP(i, N) cin >> T[i + 1];
  vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
  vector<int> next(N);
  REP(i, N) {
    int idx = lower_bound(ALL(T), T[i] + X) - T.begin();
    if (idx > N or T[idx] + X > T[i] + X) {
      next[i] = idx - 1;
    } else {
      next[i] = idx;
    }
  }
  REP(i, N) {
    REP(j, N) {
      dp[next[i]][j + 1] = max(dp[next[i]][j + 1], dp[i][j] + T[next[i]] - T[i]);
      if (next[i] < N) {
        dp[next[i] + 1][j + 1] = max(dp[next[i] + 1][j + 1], dp[i][j] + X);
      }
    }
  }
  FOR(i, 1, N + 1) {
    int ans = 0;
    REP(j, N + 1) ans = max(ans, dp[j][i]);
    cout << ans << endl;
  }

  return 0;
}
