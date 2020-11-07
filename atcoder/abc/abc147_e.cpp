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
  int H, W; cin >> H >> W;
  int M = 80 * (H + W) * 2;
  int geta = 80 * (H + W);
  vector<vector<vector<bool>>> mp(H, vector<vector<bool>>(W, vector<bool>(M, false)));
  vector<vector<int>> red(H, vector<int>(W)), blue(H, vector<int>(W));
  REP(i, H) REP(j, W) cin >> red[i][j];
  REP(i, H) REP(j, W) cin >> blue[i][j];
  mp[0][0][geta] = true;
  REP(r, H) REP(c, W) {
    //cerr << r << ',' << c << ':';
    int diff = red[r][c] - blue[r][c];
    REP(v, M) {
      if (not mp[r][c][v]) continue;
      if (r < H - 1) {
        if (v + diff < M) mp[r+1][c][v+diff] = true;
        if (v - diff >= 0) mp[r+1][c][v-diff] = true;
      }
      if (c < W - 1) {
        if (v + diff < M) mp[r][c+1][v+diff] = true;
        if (v - diff >= 0) mp[r][c+1][v-diff] = true;
      }
    }
    //cerr << endl;
  }

  int ans = 80 * 80 * 80 * 80;
  int diff = red[H-1][W-1] - blue[H-1][W-1];
  REP(v, M) {
    if (mp[H-1][W-1][v]) {
      ans = min(ans, min(std::abs(v + diff - geta), std::abs(v - diff - geta)));
    }
  }
  cout << ans << endl;
  return 0;
}
