#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(ll)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

ll dp1[210][2000][2], dp2[210][2000][2];
const ll mod = 1000000009;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string M, D;
  cin >> M >> D;

  const ll L1 = M.size();
  dp1[0][0][0] = 1LL;
  REP(pos, L1) {
    REP(sum, 2000) {
      REP(cond, 2) {
	if (!dp1[pos][sum][cond]) continue;
	if (cond == 1) {
	  // no limit
	  REP(i, 10) {
	    dp1[pos+1][sum+i][1] += dp1[pos][sum][1];
	    dp1[pos+1][sum+i][1] %= mod;
	  }
	} else {
	  REP(i, M[pos]-'0') {
	    dp1[pos+1][sum+i][1] += dp1[pos][sum][0];
	    dp1[pos+1][sum+i][1] %= mod;
	  }
	  dp1[pos+1][sum+(M[pos]-'0')][0] += dp1[pos][sum][0];
	  dp1[pos+1][sum+(M[pos]-'0')][0] %= mod;
	}
      }
    }
  }

  const ll L2 = D.size();
  dp2[0][0][0] = 1LL;
  REP(pos, L2) {
    REP(sum, 2000) {
      REP(cond, 2) {
	if (!dp2[pos][sum][cond]) continue;
	if (cond == 1) {
	  // no limit
	  REP(i, 10) {
	    dp2[pos+1][sum+i][1] += dp2[pos][sum][1];
	    dp2[pos+1][sum+i][1] %= mod;
	  }
	} else {
	  REP(i, D[pos]-'0') {
	    dp2[pos+1][sum+i][1] += dp2[pos][sum][0];
	    dp2[pos+1][sum+i][1] %= mod;
	  }
	  dp2[pos+1][sum+(D[pos]-'0')][0] += dp2[pos][sum][0];
	  dp2[pos+1][sum+(D[pos]-'0')][0] %= mod;
	}
      }
    }
  }

  ll ret = 0;
  FOR(i, 1, 2000) {
    ret += (((dp1[L1][i][0] + dp1[L1][i][1]) % mod) * ((dp2[L2][i][0] + dp2[L2][i][1]) % mod)) % mod;
    ret %= mod;
  }
  cout << ret << endl;  
  return 0;
}
