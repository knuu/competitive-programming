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
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

void print(int a, int b, int c, int d, int e, int f) {
  cout << "(" << a << "," << b << "),(" << c << "," << d << "),(" << e << "," << f << ")\n";
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int H, W; cin >> H >> W;
  vector<vector<int>> board(H, vector<int>(W, 0));
  REP(i, H) {
    string row; cin >> row;
    REP(j, W) board[i][j] = row[j] == '.' ? 0 : 1;
  }

  ll ans = 0;
  REP(i, H) {
    REP(j, W) FOR(k, j + 1, W) {
      if ((j + k) % 2 != 0 or not board[i][j] or not board[i][k]) continue;
      int mid = (j + k) / 2, d = (k - j) / 2;
      if (i - d >= 0 and board[i - d / 2][mid]) ans++, print(i, j, i, k, i - d, mid);
      if (i + d < H and board[i + d / 2][mid]) ans++, print(i, j, i, k, i + d, mid);
    }
  }
  REP(i, W) {
    REP(j, H) FOR(k, j + 1, H) {
      if ((j + k) % 2 != 0 or not board[j][i] or not board[k][i]) continue;
      int mid = (j + k) / 2, d = (k - j) / 2;
      //cout << mid << " " << d << " " << i - d << " " << (i - d >= 0) << endl;
      if (i - d >= 0 and board[mid][i - d]) ans++, print(j, i, k, i, mid, i - d);
      if (i + d < W and board[mid][i + d]) ans++, print(j, i, k, i, mid, i + d);
    }
  }
  vector<vector<int>> new_board(H + W, vector<int>(H + W, 0));
  REP(i, H) REP(j, W) {
    new_board[i + j][i - j + W] = board[i][j];
  }
  REP(i, H + W) {
    REP(j, H + W) FOR(k, j + 1, H + W) {
      if (j == k or not new_board[i][j] or not new_board[i][k]) continue;
      int mid = (j + k) / 2, d = k - j;
      if (mid % 2 == 0) {
        if (i - d >= 0 and new_board[i - d][mid]) ans++, print((i + j - W) / 2, (i - j + W) / 2, (i + k - W) / 2, (i - k + W) / 2, (i - d + mid - W) / 2, (i - d - mid + W) / 2);
        if (i + d < H + W and new_board[i + d][mid]) ans++, print((i + j - W) / 2, (i - j + W) / 2, (i + k - W) / 2, (i - k + W) / 2, (i + d + mid - W) / 2, (i + d - mid + W) / 2);
      } else {
        if (mid - 1 >= 0 and i - d >= 0 and new_board[i - d][mid - 1]) ans++, print((i + j - W) / 2, (i - j + W) / 2, (i + k - W) / 2, (i - k + W) / 2, (i - d + mid - 1 - W) / 2, (i - d - mid + 1 + W) / 2);
        if (mid + 1 < H + W and i - d >= 0 and new_board[i - d][mid + 1]) ans++, print((i + j - W) / 2, (i - j + W) / 2, (i + k - W) / 2, (i - k + W) / 2, (i - d + mid + 1 - W) / 2, (i - d - mid - 1 + W) / 2);
        if (mid - 1 >= 0 and i + d < H + W and new_board[i + d][mid - 1]) ans++, print((i + j - W) / 2, (i - j + W) / 2, (i + k - W) / 2, (i - k + W) / 2, (i + d + mid - 1 - W) / 2, (i + d - mid + 1 + W) / 2);
        if (mid + 1 < H + W and i + d < H + W and new_board[i + d][mid + 1]) ans++, print((i + j - W) / 2, (i - j + W) / 2, (i + k - W) / 2, (i - k + W) / 2, (i + d + mid + 1 - W) / 2, (i + d - mid - 1 + W) / 2);
      }
    }
  }

  REP(i, H + W) {
    REP(j, H + W) FOR(k, j + 1, H + W) {
      if (j == k or not new_board[j][i] or not new_board[k][i]) continue;
      int mid = (j + k) / 2, d = k - j;
      if (mid % 2 == 0) {
        if (i - d >= 0 and new_board[mid][i - d]) ans++, print((j + i - W) / 2, (j - i + W) / 2, (k + i - W) / 2, (k - i + W) / 2, (i - d - mid + W) / 2, (i - d + mid - W) / 2);
        if (i + d < H + W and new_board[mid][i + d]) ans++, print((j + i - W) / 2, (j - i + W) / 2, (k + i - W) / 2, (k - i + W) / 2, (i - d - mid + W) / 2, (i - d + mid - W) / 2);
      } else {
        if (mid - 1 >= 0 and i - d >= 0 and new_board[mid - 1][i - d]) ans++, print((j + i - W) / 2, (j - i + W) / 2, (k + i - W) / 2, (k - i + W) / 2, (mid - 1 + i - d - W) / 2, (mid - 1 - i + d + W) / 2);
        if (mid + 1 < H + W and i - d >= 0 and new_board[mid + 1][i - d]) ans++, print((j + i - W) / 2, (j - i + W) / 2, (k + i - W) / 2, (k - i + W) / 2, (mid + 1 + i - d - W) / 2, (mid + 1 - i + d + W) / 2);
        if (mid - 1 >= 0 and i + d < H + W and new_board[mid - 1][i + d]) ans++, print((j + i - W) / 2, (j - i + W) / 2, (k + i - W) / 2, (k - i + W) / 2, (mid - 1 + i + d - W) / 2, (mid - 1 - i - d + W) / 2);
        if (mid + 1 < H + W and i + d < H + W and new_board[mid + 1][i + d]) ans++, print((j + i - W) / 2, (j - i + W) / 2, (k + i - W) / 2, (k - i + W) / 2, (mid + 1 + i + d - W) / 2, (mid + 1 - i - d + W) / 2);
      }
    }
  }

  cout << ans << endl;
  return 0;
}
