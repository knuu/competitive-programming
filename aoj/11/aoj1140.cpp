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

const int INF = 1000;
int tile[20][20], A[11][11], dist[20][20], dp[1<<10][11], cnt;

int dpdp(int state, int v) {
  if (state == (1 << cnt) - 1) return dp[state][v] = 0;
  if (dp[state][v] != -1) return dp[state][v];

  int ret = INF;
  REP(i, cnt) {
    if (!(state >> i & 1)) {
      ret = min(ret, dpdp(state | 1 << i, i + 1) + A[v][i+1]);
    }
  }
  return dp[state][v] = ret;;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (true) {
    int R, C;
    cin >> C >> R;
    if (R == 0 && C == 0) break;
    cnt = 0;
    REP(i, R) {
      string row;
      cin >> row;
      REP(j, C) {
	if (row[j] == 'o') tile[i][j] = 0;
	else if (row[j] == '*') tile[i][j] = ++cnt;
	else if (row[j] == 'x') tile[i][j] = -1;
	else tile[i][j] = -2;
      }
    }
    REP(i, cnt + 1) REP(j, cnt + 1) A[i][j] = INF;
    REP(i, R) REP(j, C) {
      if (tile[i][j] >= 0) {
	REP(r, R) REP(c, C) dist[r][c] = INF;
	dist[i][j] = 0;
	queue<T> que;
	que.push(T(0, i, j));
	while (!que.empty()) {
	  int d, r, c;
	  tie(d, r, c) = que.front(); que.pop();
	  if (dist[r][c] != d) continue;
	  
	  REP(i, 4) {
	    int nr = r + dr[i], nc = c + dc[i];
	    if (0 <= nr && nr < R && 0 <= nc && nc < C && tile[nr][nc] != -1 && d + 1 < dist[nr][nc]) {
	      dist[nr][nc] = d + 1;
	      que.push(T(d + 1, nr, nc));
	    }
	  }
	}
	REP(r, R) REP(c, C) if (tile[r][c] >= 0) A[tile[i][j]][tile[r][c]] = dist[r][c];
      }
    }
    //REP(i, cnt + 1) REP(j, cnt + 1) cout << A[i][j] << (j == cnt ? '\n' : ' ');

    bool flag = true;
    REP(i, cnt + 1) REP(j, cnt + 1) if (A[i][j] == INF) flag = false;
    if (!flag) {
      cout << -1 << endl;
      continue;
    }

    memset(dp, -1, sizeof(dp));
    cout << dpdp(0, 0) << endl;
  }
  return 0;
}
