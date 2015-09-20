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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M;
  string maze[128];

  cin >> N >> M;
  REP(i, N) cin >> maze[i];

  int sr, sc;
  REP(i, N) REP(j, M) {
    if (maze[i][j] == 'S') {
      sr = i, sc = j;
    }
  }

  queue<T> que;
  que.push(T(sr, sc, 0));
  maze[sr][sc] = '.';

  while (!que.empty()) {
    int r, c, count;
    tie(r, c, count) = que.front(); que.pop();
    if (maze[r][c] == 'G') {
      cout << count << endl;
      return 0;
    }
    if (maze[r][c] != '.') continue;
    maze[r][c] = '#';
    REP(i, 4) {
      int nr = r+dr[i], nc = c+dc[i];
      if (0 <= nr && nr < N && 0 <= nc && nc < M && maze[nr][nc] != '#') {
	que.push(T(nr, nc, count + 1));
      }
    }
  }
  cout << -1 << endl;

  return 0;
}
