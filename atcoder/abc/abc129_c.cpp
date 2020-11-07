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
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ll N, M; cin >> N >> M;
  vector<ll> dp(N+1, 0);
  vector<bool> kaidan(N+1, true);
  ll mod = 1e9+7;
  dp[0] = 1;
  REP(i, M) {
    int d; cin >> d; kaidan[d] = false;
  }
  REP(i, N) {
    if (kaidan[i]) dp[i+1] += dp[i];
    if (i > 0 and kaidan[i-1]) dp[i+1] += dp[i-1];
    dp[i+1] %= mod;
  }
  cout << dp[N] << endl;



  return 0;
}
