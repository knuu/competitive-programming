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

int dp[10010][101][2];
const int mod = 1000000007;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string N;
  int D;
  cin >> D >> N;
  int L = (int)N.size();
  dp[0][0][0] = 1;

  REP(len, L) {
    REP(s, D) {
      REP(cond, 2) {
	if (cond == 1) {
	  // no limit
	  REP(i, 10) {
	    dp[len+1][(s+i)%D][1] += dp[len][s][1];
	    dp[len+1][(s+i)%D][1] %= mod;
	  }
	} else {
	  // has limit
	  REP(i, N[len]-'0') {
	    dp[len+1][(s+i)%D][1] += dp[len][s][0];
	    dp[len+1][(s+i)%D][1] %= mod;
	  }
	  dp[len+1][(s+(N[len]-'0'))%D][0] += dp[len][s][0];
	  dp[len+1][(s+(N[len]-'0'))%D][0] %= mod;
	}
      }
    }
  }
  cout << (dp[L][0][0] + dp[L][0][1] + mod - 1) % mod << endl;  
  return 0;
}
