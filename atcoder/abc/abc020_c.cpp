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
const int INF = 1<<30;
int H, W;

bool in(int r, int c) { return 0 <= r && r < H && 0 <= c && c < W; }

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int time;
  string board[16];
  cin >> H >> W >> time;
  REP(i, H) cin >> board[i];

  int sr = 0, sc = 0, gr = 0, gc = 0;
  REP(i, H) REP(j, W) {
    if (board[i][j] == 'S')
      sr = i, sc = j;
    if (board[i][j] == 'G')
      gr = i, gc = j;
  }

  int low = 1, high = INF;
  while (low + 1 < high) {
    int mid = (low + high) / 2;
    int dist[16][16];
    REP(i, H) REP(j, W) dist[i][j] = INF;
    dist[sr][sc] = 0;
    priority_queue<T, vector<T>, greater<T>> que;
    que.push(T(0, sr, sc));

    while (!que.empty()) {
      int r, c, cost;
      tie(cost, r, c) = que.top(); que.pop();

      if (dist[r][c] < cost) continue;

      REP(i, 4) {
	int nr = r+dr[i], nc = c+dc[i];
	if (in(nr, nc)) {
	  int ncost = (board[nr][nc] == '#' ? mid : 1);
	  if (dist[nr][nc] > dist[r][c] + ncost) {
	    dist[nr][nc] = dist[r][c] + ncost;
	    que.push(T(dist[nr][nc], nr, nc));
	  }
	}
      }
    }

    if (dist[gr][gc] <= time) {
      low = mid;
    } else {
      high = mid;
    }
  }

  cout << low << endl;
  return 0;
}
