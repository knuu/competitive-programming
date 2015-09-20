#include <iostream>
#include <cstring>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int N, M;
int tile[16][16];

int flip[16][16];
int opt[16][16];

const int dr[5] = {-1, 0, 0, 1, 0};
const int dc[5] = {0, 1, 0, 0, -1};
  

bool is_white(int r, int c) {
  int count = tile[r][c];
  REP(i, 5) {
    int nr = r+dr[i], nc = c+dc[i];
    if (0 <= nr && nr < M && 0 <= nc && nc < N) {
      count += flip[nr][nc];
    }
  }
  return count % 2 == 0;
}

int calc() {
  FOR(r, 1, M) REP(c, N) {
    if (!is_white(r-1, c)) flip[r][c] = 1;
  }

  REP(c, N) {
    if (!is_white(M-1, c)) return -1;
  }

  int count = 0;
  REP(r, M) REP(c, N) count += flip[r][c];
  
  return count;
}

int main() {
  ios_base::sync_with_stdio(false);

  cin >> M >> N;
  REP(r, M) REP(c, N) cin >> tile[r][c];

  int ans = -1;
  REP(i, 1<<N) {
    memset(flip, 0, sizeof(flip));
    REP(j, N) flip[0][N-j-1] = i >> j & 1;

    int cand = calc();
    if (cand != -1 && (ans == -1 || cand < ans)) {
      ans = cand;
      memcpy(opt, flip, sizeof(flip));
    }	
  }

  if (ans == -1) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    REP(r, M) REP(c, N) cout << opt[r][c] << (N-1==c ? '\n' : ' ');
  }
	   
  return 0;
}
