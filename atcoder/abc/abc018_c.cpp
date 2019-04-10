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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int R, C, K; cin >> R >> C >> K;
  vector<string> board(R);
  REP(i, R) cin >> board[i];
  vector<vector<int>> row_left(R, vector<int>(C, 0)), row_right(R, vector<int>(C, 0));
  REP(i, R) REP(j, C) {
    for (int l = j; l >= 0 and board[i][l] == 'o'; l--) row_left[i][j]++;
    for (int r = j; r < C and board[i][r] == 'o'; r++) row_right[i][j]++;
  }

  int ans = 0;
  REP(i, R) REP(j, C) {
    if (min(i, j) - (K - 1) < 0 or i + (K - 1) >= R or j + (K - 1) >= C) continue;
    bool flag = true;
    for (int up = i, down = i, rest = K; rest > 0; up--, down++, rest--) {
      if (row_left[up][j] < rest or row_right[up][j] < rest or row_left[down][j] < rest or row_right[down][j] < rest) {
        flag = false;
        break;
      }
    }
    if (flag) ans++;
  }
  cout << ans << endl;
  return 0;
}
