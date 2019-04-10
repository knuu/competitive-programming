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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int R, C;
inline bool in(int r, int c) { return 0 <= r and r < R and 0 <= c and c < C; }

int bfs(vector<vector<int>> B) {
  int sr = 0, sc = 0, gr = 0, gc = 0;
  REP(i, R) REP(j, C) {
    if (B[i][j] == 2) sr = i, sc = j;
    if (B[i][j] == 3) gr = i, gc = j;
  }

  vector<vector<bool>> board(R, vector<bool>(C, false));
  REP(i, R) REP(j, C) board[i][j] = B[i][j] == 0;
  board[sr][sc] = board[gr][gc] = true;

  queue<tuple<int, int, vector<vector<bool>>, int>> que;
  que.emplace(sr, sc, board, 0);
  while (not que.empty()) {
    int r, c, cnt; vector<vector<bool>> board; tie(r, c, board, cnt) = que.front(); que.pop();

    REP(i, 4) {
      int nr = r + dr[i], nc = c + dc[i];
      if (in(nr, nc) and board[nr][nc]) {
        while (in(nr, nc) and board[nr][nc]) {
          if (nr == gr and nc == gc) return cnt + 1;
          nr += dr[i], nc += dc[i];
        }
        if (in(nr, nc) and cnt < 9) {
          vector<vector<bool>> next_board = board;
          next_board[nr][nc] = true;
          que.emplace(nr - dr[i], nc - dc[i], next_board, cnt + 1);
        }
      }
    }
  }
  return -1;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  while (true) {
    cin >> C >> R;
    if (R == 0 and C == 0) break;
    vector<vector<int>> B(R, vector<int>(C)); REP(i, R) REP(j, C) cin >> B[i][j];
    cout << bfs(B) << endl;
  }


  return 0;
}
