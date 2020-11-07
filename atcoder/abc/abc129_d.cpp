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
  vector<string> board;
  REP(i, H) {
    string row; cin >> row;
    board.emplace_back(row);
  }

  vector<vector<int>> ans(H, vector<int>(W, 1));
  REP(r, H) {
    int now = 0, now_rev = 0;
    REP(c, W) {
      if (board[r][c] == '#') {
        now = 0;
      } else {
        ans[r][c] += now;
        now++;
      }

      if (board[r][W-c-1] == '#') {
        now_rev = 0;
      } else {
        ans[r][W-c-1] += now_rev;
        now_rev++;
      }
    }
  }

  REP(c, W) {
    int now = 0, now_rev = 0;
    REP(r, H) {
      if (board[r][c] == '#') {
        now = 0;
      } else {
        ans[r][c] += now;
        now++;
      }

      if (board[H-r-1][c] == '#') {
        now_rev = 0;
      } else {
        ans[H-r-1][c] += now_rev;
        now_rev++;
      }
    }
  }

  int ans_val = 0;
  REP(i, H) REP(j, W) ans_val = max(ans_val, ans[i][j]);
  cout << ans_val << endl;
  //REP(i, H) REP(j, W) cout << ans[i][j] << (j == W-1 ? '\n' : ' ');


  return 0;
}
