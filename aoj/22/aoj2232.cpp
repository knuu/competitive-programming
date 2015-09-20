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

string b[32];
int H, W, n;

bool can_clear(int h, int w) {
  int cnt_h = 1;
  int hi = h+1;
  while (hi < H && b[hi][w] == b[h][w]) hi++, cnt_h++;
  hi = h-1;
  while (0 <= hi && b[hi][w] == b[h][w]) hi--, cnt_h++;
  if (cnt_h >= n) return true;

  int cnt_w = 1;
  int wi = w+1;
  while (wi < W && b[h][wi] == b[h][w]) wi++, cnt_w++;
  wi = w-1;
  while (0 <= wi && b[h][wi] == b[h][w]) wi--, cnt_w++;

  return cnt_w >= n;
}

void drop() {
  for (int j = W-1; j >= 0; j--) {
    for (int i = H-1, bottom = H-1; i >= 0; i--) {
      if (b[i][j] != '.') {
	swap(b[i][j], b[bottom][j]);
	bottom--;
      }
    }
  }
}

bool can_all_clear() {
  drop();  
  bool do_clear[32][32];
  bool flag = true;
  while (flag) {
    flag = false;
    REP(i, H) REP(j, W)
      do_clear[i][j] = b[i][j] != '.' && can_clear(i, j);
    REP(i, H) REP(j, W) {
      if (do_clear[i][j]) {
	b[i][j] = '.';
	flag = true;
      }
    }
    drop();
  }
  REP(i, H) REP(j, W) {
    if (b[i][j] != '.') return false;
  }
  return true;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> H >> W >> n;
  string board[32];
  REP(i, H) cin >> board[i];

  REP(i, H) b[i] = board[i];
  if (can_all_clear()) {
    cout << "YES" << endl;
    return 0;
  }

  REP(i, H) REP(j, W-1) {
    if (board[i][j] == '.' && board[i][j+1] == '.') continue;
    REP(l, H) b[l] = board[l];
    swap(b[i][j], b[i][j+1]);
    if (can_all_clear()) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
