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

int dp[16][16][2];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string N;
  cin >> N;
  int L = N.size();

  dp[0][0][0] = 1;
  REP(pos, L) {
    REP(cnt, L+1) {
      REP(cond, 2) {
	if (!dp[pos][cnt][cond]) continue;
	
	int D = N[pos] - '0';
	if (cond == 1) {
	  REP(d, 10) {
	    dp[pos+1][cnt + (d == 1)][1] += dp[pos][cnt][1];
	  }
	} else {
	  REP(d, D) {
	    dp[pos+1][cnt + (d == 1)][1] += dp[pos][cnt][0];
	  }
	  dp[pos+1][cnt + (D == 1)][0] += dp[pos][cnt][0];
	}
      }
    }
  }

  int ans = 0;
  REP(i, L+1) REP(j, 2) {
    ans += dp[L][i][j] * i;
  }
  /*  REP(i, L+1) {
    REP(j, L+1) REP(k, 2) cout << dp[i][j][k] << (k == 1 ? '\t' : ' ');
    cout << endl;
    }*/

  cout << ans << endl;
  return 0;
}
