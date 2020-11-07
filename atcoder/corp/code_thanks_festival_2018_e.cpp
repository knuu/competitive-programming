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

  int T; cin >> T;
  vector<int> A(T); REP(i, T) cin >> A[i];
  vector<vector<ll>> dp(T, vector<ll>(600, 0));
  const ll MOD = 1e9+7;

  REP(i, A[0]) dp[0][i+1] = 1;
  ll ans = dp[0][1];
  REP(i, T-1) {
    // i 以下で i を作る場合
    REP(j, 600) {
      for (int k = 2; k < 600; k += 2) {
        dp[i+1][k/2] = dp[i][k];
      }
    }

    for (int j = 599; j >= 0; j--) {
      for (int k = 1; k <= A[i+1] and j-k >= 0; k++) {
        dp[i+1][j] = (dp[i+1][j] + dp[i+1][j-k]) % MOD;
      }
    }

    REP(j, A[i+1]) dp[i+1][j+1]++;

    ans = (ans + dp[i+1][1]) % MOD;
  }
  ans = (ans + dp[T-1][2]) % MOD;
  REP(i, T) REP(j, 10) cout << dp[i][j] << (j == 9 ? '\n' : ' ');
  cout << ans << endl;

  return 0;
}
