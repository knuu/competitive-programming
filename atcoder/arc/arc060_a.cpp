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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, A; cin >> N >> A;
  vector<int> X(N); REP(i, N) cin >> X[i];
  int S = accumulate(ALL(X), 0);
  vector<vector<ll>> dp(N+1, vector<ll>(S+1, 0));
  dp[0][0] = 1;
  REP(k, N) {
    for (int i = N-1; i >= 0; i--) {
      for (int j = S-1; j >= 0; j--) {
        if (j + X[k] <= S) dp[i+1][j+X[k]] += dp[i][j];
      }
    }
  }

  ll ans = 0;
  FOR(i, 1, N+1) if (i * A <= S) ans += dp[i][i * A];
  cout << ans << endl;

  //REP(i, S+1) cout << dp[N][i] << (i == S ? '\n' : ' ');

  return 0;
}
