#include <iostream>
#include <string>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

string yard[128];
int N, M;

void dfs(int r, int c) {
  if (yard[r][c] != 'W') return;

  yard[r][c] = 'x';
  REP(i, 8) {
    int nr = r+dr[i], nc = c+dc[i];
    if (0 <= nr && nr < N && 0 <= nc && nc < M) {
      dfs(nr, nc);
    }
  }
  return;
}
  

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  REP(i, N) cin >> yard[i];

  int ans = 0;
  REP(i, N)  REP(j, M) {
    if (yard[i][j] == 'W') {
      ans++;
      dfs(i, j);
    }
  }
  cout << ans << endl;
  return 0;
}
