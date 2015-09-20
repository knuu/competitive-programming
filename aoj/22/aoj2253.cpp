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
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

const int dx[6] = {0, 1, 1, 0, -1, -1};
const int dy[6] = {1, 1, 0, -1, -1, 0};

int board[128][128];
int geta = 64;

int main() {
  ios_base::sync_with_stdio(false);

  while (1) {
    int t, n;
    cin >> t >> n;
    if (t == 0 && n == 0) break;
    memset(board, 0, sizeof(board));
    REP(i, n) {
      int x, y;
      cin >> x >> y;
      board[y+geta][x+geta] = -1;
    }
    int sx, sy;
    cin >> sx >> sy;

    queue<T> que;
    que.push(T(sx, sy, t));

    while (!que.empty()) {
      int x, y, rest;
      tie(x, y, rest) = que.front();
      que.pop();

      if (rest < 0 || board[y+geta][x+geta] != 0) continue;

      board[y+geta][x+geta] = 1;
      REP(i, 6) {
	int nx = x + dx[i], ny = y + dy[i];
	  que.push(T(nx, ny, rest - 1));
      }
    }      
      
    int ans = 0;
    REP(i, 128) REP(j, 128) ans += board[i][j] > 0;
    cout << ans << endl;
  }
    
  return 0;
}
