#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int INF = 1<<30;

int dp[2048][2048];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string S;
  cin >> S;
  
  int N = S.size();
  assert(N <= 1000);

  REP(i, N) REP(j, 2048) dp[i][j] = -INF;
  int geta = 1024;
  dp[0][0+geta] = 0;
  
  REP(i, N) {
    FOR(j, -N + geta, N + geta) {
      if (dp[i][j] == -INF) continue;
      if (S[i] == 'M') {
	dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
	dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j]);
      } else if (S[i] == '+') {
	dp[i+1][j] = max(dp[i+1][j], dp[i][j] + (j-geta));

      } else if (S[i] == '-') {
	dp[i+1][j] = max(dp[i+1][j], dp[i][j] - (j-geta));
      }
    }
  }
  cout << dp[N][0+geta] << endl;
  return 0;
}
