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

int main() {
  int R, C, sr, sc, gr, gc;
  int dr[4] = {-1, 0, 1, 0};
  int dc[4] = {0, 1, 0, -1};
  string maze[64];
  queue<T> que;

  cin >> R >> C >> sr >> sc >> gr >> gc;
  sr--, sc--, gr--, gc--;
  REP(i, R) cin >> maze[i];

  que.push(T(sr, sc, 0));
  while (!que.empty()) {
    int r, c, d;
    tie(r, c, d) = que.front(); que.pop();
    if (r == gr && c == gc) {
      cout << d << endl;
      break;
    }
    if (maze[r][c] != '.') continue;
    maze[r][c] = 'x';
    REP(i, 4) {
      int nr = r + dr[i], nc = c + dc[i];
      if (maze[nr][nc] == '.') que.push(T(nr, nc, d+1));
    }
  }
  return 0;
}
