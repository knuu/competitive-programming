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

int width[10010], value[10010];
int dp[64][10010][64];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int W, N, K;
  cin >> W >> N >> K;
  REP(i, N) cin >> width[i] >> value[i];
  
  REP(i, N) {
    REP(j, W+1) {
      REP(k, K) {
	if (j >= width[i]) {
	  dp[i+1][j][k+1] = max(dp[i][j][k+1],
				dp[i][j-width[i]][k] + value[i]);
	} else {
	  dp[i+1][j][k+1] = dp[i][j][k+1];
	}
	//cout << i << ',' << j << ',' << k << ':' << dp[i+1][j][k+1] << endl;
      }
    }
  }

  int ans = 0;
  REP(j, W+1) REP(k, K+1) ans = max(ans, dp[N][j][k]);
  cout << ans << endl;
  return 0;
}
