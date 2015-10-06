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

ll dp[1024];
const ll mod = 1000000007;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string X, S, T;
  cin >> X >> S >> T;

  dp[0] = 1;
  REP(i, X.size()) {
    if (S == X.substr(i, S.size())) {
      dp[i+(int)S.size()] += dp[i];
      dp[i+(int)S.size()] %= mod;
    }
    if (T == X.substr(i, T.size())) {
      dp[i+(int)T.size()] += dp[i];
      dp[i+(int)T.size()] %= mod;
    }
  }

  cout << dp[X.size()] << endl;
  return 0;
}
