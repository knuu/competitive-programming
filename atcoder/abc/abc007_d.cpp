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

ll dp[20][10][2];

ll dpdp(string N) {
  const int L = N.size();

  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  REP(pos, L) {
    REP(d, 10) {
      if (d == 4 || d == 9) continue;
      REP(flag, 2) {
	if (!dp[pos][d][flag]) continue;
	if (flag == 1) {
	  REP(i, 10) {
	    if (i == 4 || i == 9) continue;
	    dp[pos+1][i][1] += dp[pos][d][1];
	  }
	} else {
	  REP(i, N[pos]-'0') {
	    if (i == 4 || i == 9) continue;
	    dp[pos+1][i][1] += dp[pos][d][0];
	  }
	  dp[pos+1][N[pos]-'0'][0] = dp[pos][d][0];
	}
      }
    }
  }
  ll ret = 0;
  REP(i, 10) REP(j, 2) {
    if (i == 4 || i == 9) continue;
    ret += dp[L][i][j];
  }
  return ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll A, B;
  cin >> A >> B;

  cout << (B-A+1) - (dpdp(to_string(B)) - dpdp(to_string(A-1))) << endl;
  return 0;
}
