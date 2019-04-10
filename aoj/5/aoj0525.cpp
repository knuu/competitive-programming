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

  while (true) {
    int R, C; cin >> R >> C;
    if (R == 0 and C == 0) break;
    vector<vector<int>> board(R, vector<int>(C));
    REP(i, R) REP(j, C) cin >> board[i][j];
    int ans = 0;
    REP(r_state, 1 << R) {
      int cnt = 0;
      REP(c, C) {
        int c_cnt = 0;
        REP(r, R) c_cnt += (board[r][c] + (r_state >> r & 1)) % 2 == 0;
        cnt += max(c_cnt, R - c_cnt);
      }
      ans = max(ans, cnt);
    }
    cout << ans << endl;
  }

  return 0;
}
