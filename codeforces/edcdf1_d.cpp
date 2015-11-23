#include <bits/stdc++.h>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
int board[1010][1010], kind[1000010];
int R, C;

void dfs(int r, int c, int k) {
  board[r][c] = k;
  REP(i, 4) {
    int nr = r + dr[i], nc = c + dc[i];
    if (board[nr][nc] == -1) {
      kind[k]++;
    } else if (board[nr][nc] == 0) {
      dfs(nr, nc, k);
    }
  }
}


int main() {
  int K, cnt = 0;
  scanf("%d %d %d", &R, &C, &K);
  REP(i, R) {
    string row;
    cin >> row;
    REP(j, C) board[i][j] = (row[j] == '*' ? -1 : 0);
  }
  REP(i, R) REP(j, C) {
    if (board[i][j] == 0) {
      cnt++;
      dfs(i, j, cnt);
    }
  }
  REP(i, K) {
    int r, c;
    scanf("%d %d", &r, &c); r--, c--;
    assert(board[r][c] > 0);
    printf("%d\n", kind[board[r][c]]);
  }
  return 0;
}
