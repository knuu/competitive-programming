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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  const int maxC = 50;
  int N, W, C; cin >> N >> W >> C;
  vector<vector<pair<int, int>>> goods(maxC);
  REP(i, N) {
    int w, v, c; cin >> w >> v >> c;
    goods[c-1].emplace_back(w, v);
  }

  vector<vector<int>> dp(C + 1, vector<int>(W + 1, 0));

  REP(i, 50) {
    for (int c = C-1; c >= 0; c--) {
      vector<int> tmp = dp[c];
      for (auto g : goods[i]) {
        int w, v; tie(w, v) = g;
        for (int j = W; j >= w; j--) tmp[j] = max(tmp[j], tmp[j-w] + v);
      }
      REP(j, W + 1) dp[c+1][j] = max(dp[c+1][j], tmp[j]);
    }
  }

  int ans = 0;
  REP(i, C+1) ans = max(ans, *max_element(ALL(dp[i])));
  cout << ans << endl;
  return 0;
}
