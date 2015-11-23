#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
const int INF = 1<<29;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int change_d[5] = {0, 1, 2, 3, 0};
  while (true) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    int ope[31][31], dist[31][31][4], ch_cost[4];
    REP(i, h) REP(j, w) cin >> ope[i][j];
    REP(i, 4) cin >> ch_cost[i];
    REP(i, h) REP(j, w) REP(k, 4) dist[i][j][k] = INF;
    dist[0][0][1] = 0;
    priority_queue<T> pque;
    pque.push(T(0, 0, 1));
    while (!pque.empty()) {
      int d, r, c, dir;
      tie(d, r, dir) = pque.top(); pque.pop();
      d = -d, c = r % w, r /= w;
      //cout << c << ',' << r << ',' << dir << ':' << d << endl;
      if (dist[r][c][dir] < d || (r == h-1 && c == w-1)) continue;
      int default_d = ope[r][c] != 4 ? (dir + change_d[ope[r][c]]) % 4 : 4;
      REP(i, 4) {
	int nd = (dir + i) % 4, nr = r + dr[nd], nc = c + dc[nd], cost = (nd == default_d ? 0 : ch_cost[i]);
	//cout << nr << ',' << nc << endl;
	if (0 <= nr && nr < h && 0 <= nc && nc < w && dist[nr][nc][nd] > d + cost) {
	  dist[nr][nc][nd] = d + cost;
	  pque.push(T(-dist[nr][nc][nd], nr * w + nc, nd));
	}
      }      
    }
    int ret = INF;
    REP(i, 4) ret = min(ret, dist[h-1][w-1][i]);
    cout << ret << endl;
  }
  return 0;
}
