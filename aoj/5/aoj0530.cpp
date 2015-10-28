#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
 
const int INF = 1<<29;
 
int dp[150][10][77];
int stones[150][10][2];
int col[150];
 
int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
 
  while (true) {
    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) break;
   
    REP(i, N) {
      cin >> col[i];
      REP(j, col[i]) {
	cin >> stones[i][j][0] >> stones[i][j][1];
      }
    }
 
    REP(i, N) REP(j, col[i]) REP(k, M+1) dp[i][j][k] = INF;
    REP(j, col[0]) dp[0][j][0] = 0;
    REP(j, col[1]) dp[1][j][1] = 0;
    REP(i, N-1) {
      REP(j, col[i+1]) {
	int x_now = stones[i+1][j][0], d_now = stones[i+1][j][1];
	REP(k, col[i]) {
	  int x_prev = stones[i][k][0], d_prev = stones[i][k][1];
	  int safe = (d_now + d_prev) * abs(x_now - x_prev);
	  REP(m, M+1) {
	    dp[i+1][j][m] = min(dp[i+1][j][m], dp[i][k][m] + safe);
	  }
	}
	if (i > 0) {
	  REP(k, col[i-1]) {
	    int x_prev = stones[i-1][k][0], d_prev = stones[i-1][k][1];
	    int safe = (d_now + d_prev) * abs(x_now - x_prev);
	    REP(m, M) {
	      dp[i+1][j][m+1] = min(dp[i+1][j][m+1], dp[i-1][k][m] + safe);
	    }
	  }
	}
      }
    }
 
    int ans = INF;
    REP(j, col[N-1]) REP(m, M+1) ans = min(ans, dp[N-1][j][m]);
    REP(j, col[N-2]) REP(m, M) ans = min(ans, dp[N-2][j][m]);
    cout << ans << endl;
  }
  return 0;
}
