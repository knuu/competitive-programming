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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

const int INF = (int)1e7;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int V, E; cin >> V >> E;
  vector<vector<int>> dp(1 << V, vector<int>(V, INF)), D(V, vector<int>(V, INF));

  REP(i, E) {
    int s, t, d; cin >> s >> t >> d;
    D[s][t] = d;
  }

  dp[(1 << V) - 1][0] = 0;
  for (int state = (1 << V) - 2; state >= 0; state--) {
    REP(i, V) REP(j, V) if ((state == 0 or (state >> i & 1)) and not (state >> j & 1) and dp[state][i] > dp[state | (1 << j)][j] + D[i][j]) {
      dp[state][i] = dp[state | (1 << j)][j] + D[i][j];
    }
  }

  cout << (dp[0][0] == INF ? -1 : dp[0][0]) << endl;
  return 0;
}
