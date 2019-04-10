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

const ll mod = 1e9+7;

const int dh[3] = {1, 0, 1};
const int dw[3] = {0, 1, 1};

ll dp[1010][1010];
int ban[1010][1010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int H, W, K; cin >> H >> W >> K;
  REP(i, K) {
    int x, y; cin >> x >> y;
    ban[1][y+2]++, ban[1][H+1]--, ban[x][y+2]--;
    ban[x+2][1]++, ban[x+2][y]--, ban[W+1][1]--;
  }
  REP(x, W+1) REP(y, H) ban[x][y+1] += ban[x][y];
  REP(y, H+1) REP(x, W) ban[x+1][y] += ban[x][y];

  dp[1][0] = 1;
  REP(x, W+1) REP(y, H) {
    if (ban[x+1][y+1]) continue;
    dp[x+1][y+1] = (dp[x][y+1] + dp[x+1][y]) % mod;
  }
  //REP(y, H+1) REP(x, W+1) cout << dp[x][y] << (x == W ? '\n' : ' ');
  cout << dp[W][H] << endl;
  return 0;
}
