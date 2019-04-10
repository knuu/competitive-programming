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
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<ll> C(N); REP(i, N) cin >> C[i];
  vector<vector<string>> S(N, vector<string>(2)); REP(i, N) cin >> S[i][0], S[i][1] = S[i][0], reverse(ALL(S[i][1]));

  //REP(i, N) REP(j, 2) cout << S[i][j] << (j == 1 ? '\n' : ' ');
  const ll INF = 1e17;
  vector<vector<ll>> dp(N, vector<ll>(2, INF));
  dp[0][0] = 0;
  dp[0][1] = C[0];
  REP(i, N-1) REP(j, 2) {
    if (S[i][0] <= S[i+1][j]) dp[i+1][j] = min(dp[i+1][j], dp[i][0] + j * C[i+1]);
    if (S[i][1] <= S[i+1][j]) dp[i+1][j] = min(dp[i+1][j], dp[i][1] + j * C[i+1]);
  }

  //REP(i, N) REP(j, 2) cout << dp[i][j] << (j == 1 ? '\n' : ' ');

  if (dp[N-1][0] == INF and dp[N-1][1] == INF) {
    cout << -1 << endl;
  } else {
    cout << min(dp[N-1][0], dp[N-1][1]) << endl;
  }
  return 0;
}
