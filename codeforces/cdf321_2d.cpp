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

const int MAX_N = 18;

ll up[20][20];
int N, M, K;
ll sat[20];
ll dp[1<<MAX_N][MAX_N];

ll dpdp(int state, int now, int res) {
  if (res == 0) {
    //cout << state << ' ' << now << ' ' << 0 << endl;
    return dp[state][now] = 0;
  }
  if (dp[state][now] != -1) return dp[state][now];

  ll ret = 0;
  REP(i, N) {
    if (!(state >> i & 1)) {
      ret = max(ret, dpdp(state | 1 << i, i, res-1) + sat[i] + (state == 0 ? 0 : up[now][i]));
    }
  }
  //cout << state << ' ' << now << ' ' << ret << endl;
  return dp[state][now] = ret;
}  

int main() {
  // use scanf in CodeForces!

  scanf("%d %d %d", &N, &M, &K);
  REP(i, N) cin >> sat[i];
  REP(i, K) {
    int x, y;
    ll c;
    cin >> x >> y >> c;
    x--, y--;
    up[x][y] = c;
  }
  memset(dp, -1, sizeof(dp));
  cout << dpdp(0, 0, M) << endl;
  return 0;
}
