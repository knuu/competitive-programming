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

string board[16];

void dfs(int r, int c) {
  if (board[r][c] != '1') return ;

  board[r][c] = '.';
  REP(i, 4) {
    int nr = r+dr[i], nc = c+dc[i];
    if (0 <= nr && nr < 12 && 0 <= nc && nc < 12) {
      dfs(nr, nc);
    }
  }
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (cin >> board[0]) {
    REP(i, 11) cin >> board[i+1];
    int cnt = 0;
    REP(r, 12) {
      REP(c, 12) {
	if (board[r][c] == '1') {
	  cnt++;
	  dfs(r, c);
	}
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
