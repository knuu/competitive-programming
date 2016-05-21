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

const ll mod = 1000000009;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, T, M; cin >> N >> T >> M;
  vector<ll> D(N); REP(i, N) cin >> D[i];

  vector<vector<ll>> dp(N+1, vector<ll>(T+1, 0));
  dp[0][0] = 1;
  REP(i, N) {
    vector<vector<ll>> _dp(N+1, vector<ll>(T+1, 0));
    REP(j, N+1) REP(k, T+1) {
      _dp[j][k] += dp[j][k];
      _dp[j][k] %= mod;
      if (j < N and k+D[i] <= T) {
        _dp[j+1][k+D[i]] += dp[j][k];
        _dp[j+1][k+D[i]] %= mod;
      }
    }
    dp = _dp;
  }
  ll ans = 0;
  FOR(i, M, N+1) REP(j, T+1) {
    ans += dp[i][j];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
