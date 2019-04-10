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

int N, M;

bool in_board(int r, int c) { return 0 <= r and r < N and 0 <= c and c < M; }

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  vector<string> board(N);
  REP(i, N) cin >> board[i];
  int ans = 0;
  REP(r1, N) REP(c1, M) {
    if (board[r1][c1] == 'B') continue;
    vector<string> work1 = board;
    int cand = 1, cnt = 1;
    work1[r1][c1] = 'B';
    while (true) {
      bool flag = true;
      REP(i, 4) {
	int nr = r1 + dr[i] * cnt, nc = c1 + dc[i] * cnt;
	if (not in_board(nr, nc) or board[nr][nc] == 'B') flag = false;
      }
      if (flag) {
	REP(i, 4) {
	  int nr = r1 + dr[i] * cnt, nc = c1 + dc[i] * cnt;
	  work1[nr][nc] = 'B';
	}
	cand += 4;
	cnt++;
      } else {
	break;
      }
    }
    //cout << '(' << r1 << ',' << c1 << ") " << cand << endl;
    REP(r2, N) REP(c2, M) {
      if (work1[r2][c2] == 'B') continue;
      int cand2 = 1, cnt = 1;
      while (true) {
	bool flag = true;
	REP(i, 4) {
	  int nr = r2 + dr[i] * cnt, nc = c2 + dc[i] * cnt;
	  if (not in_board(nr, nc) or work1[nr][nc] == 'B') flag = false;
	}
	if (flag) {
	  cand2 += 4;
	  cnt++;
	} else {
	  ans = max(ans, cand * cand2);
	  break;
	}
      }
    }
  }
  cout << ans << endl;
  return 0;
}
