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

  int N, M; cin >> N >> M;
  vector<vector<ll>> cakes(N, vector<ll>(3));
  REP(i, N) REP(j, 3) cin >> cakes[i][j];

  ll ans = 0;
  REP(bit, 1 << 3) {
    REP(i, N) REP(j, 3) {
      if (bit >> j & 1) cakes[i][j] *= -1LL;
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, -1e13));
    dp[0][0] = 0;
    REP(i, N) REP(j, M + 1) {
      if (j == 0) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = max(dp[i][j], dp[i][j - 1] + accumulate(cakes[i].begin(), cakes[i].end(), 0LL));
      }
    }
    ans = max(ans, dp[N][M]);
    REP(i, N) REP(j, 3) {
      if (bit >> j & 1) cakes[i][j] *= -1LL;
    }
  }

  cout << ans << endl;
  return 0;
}
