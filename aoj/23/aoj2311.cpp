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

const int dr[8] = {-1, -1, 1, 1, 1, -1, 0, 0};
const int dc[8] = {-1, 1, -1, 1, 0, 0, -1, 1};
  
int board[8][8];

int count_lock(int r, int c, int k) {
  int cnt = 0;
  
  REP(i, 8) {
    int nr = r+dr[i], nc = c+dc[i];
    while (0 <= nr && nr < 8 && 0 <= nc && nc < 8 && board[nr][nc] == (k^1))
      nr += dr[i], nc += dc[i];
    if (0 <= nr && nr < 8 && 0 <= nc && nc < 8 && board[nr][nc] == k) {
      if (i < 6) {
	cnt += abs(nr-r)-1;
      } else {
	cnt += abs(nc-c)-1;
      }
    }
  }
  return cnt;
}
  
void put_lock(int r, int c, int k){
  board[r][c] = k;
  REP(i, 8) {
    int nr = r+dr[i], nc = c+dc[i];
    while (0 <= nr && nr < 8 && 0 <= nc && nc < 8 && board[nr][nc] == (k^1))
      nr += dr[i], nc += dc[i];
    if (0 <= nr && nr < 8 && 0 <= nc && nc < 8 && board[nr][nc] == k) {
      nr -= dr[i], nc -= dc[i];
      while (0 <= nr && nr < 8 && 0 <= nc && nc < 8 && board[nr][nc] == (k^1)) {
	board[nr][nc] = k;
	nr -= dr[i], nc -= dc[i];
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  REP(i, 8) {
    string row;
    cin >> row;
    REP(j, 8) {
      switch(row[j]) {
      case '.':
	board[i][j] = -1;
	break;
      default:
	board[i][j] = row[j] == 'o' ? 0 : 1;
	break;
      }
    }
  }

  int flag = true;
  while (flag) {
    flag = false;
    REP(k, 2) {
      int f = 0;
      P f_p;
      REP(r, 8) REP(c, 8) {
	if (board[r][c] == -1) {
	  int cnt = count_lock(r, c, k);
	  if ((k == 0 && cnt > f) || (k == 1 && cnt > 0 && cnt >= f)) {
	    f = cnt;
	    f_p = make_pair(r, c);
	  }
	}
      }
      if (f > 0) {
	put_lock(f_p.first, f_p.second, k);
	flag = true;
      }
    }
    
  }
  REP(r, 8) {
    REP(c, 8) {
      switch(board[r][c]) {
      case -1:
	cout << '.';
	break;	
      default:
	cout << (board[r][c] == 0 ? 'o' : 'x');
	break;
      }
    }
    cout << endl;
  }
  return 0;
}
