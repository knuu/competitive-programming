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

string board[510];
int row[510][510], col[510][510];

int main() {
  int H, W; scanf("%d %d", &H, &W);
  REP(i, H) cin >> board[i];

  REP(i, H) REP(j, W-1) {
    row[i][j+1] += row[i][j];
    if (board[i][j] == '.' and board[i][j+1] == '.') row[i][j+1]++;
  }
  REP(j, W) REP(i, H-1) {
    col[i+1][j] += col[i][j];
    if (board[i][j] == '.' and board[i+1][j] == '.') col[i+1][j]++;
  }

  int Q; scanf("%d", &Q);
  REP(_, Q) {
    int r1, c1, r2, c2; scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    r1--, c1--, r2--, c2--;
    int ans = 0;
    FOR(r, r1, r2+1) ans += row[r][c2] - row[r][c1];
    FOR(c, c1, c2+1) ans += col[r2][c] - col[r1][c];
    printf("%d\n", ans);
  }
  

  return 0;
}
