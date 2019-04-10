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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  REP(testcase, T) {
    int N; cin >> N;
    assert(N <= 6);
    vector<int> B(N); REP(i, N) cin >> B[i];
    int all_state = 1;
    int H = N - 2, W = N - 2;
    REP(_, H * W) all_state *= 3;
    int ans = N + 1;
    vector<int> pow3;
    pow3.emplace_back(1);
    REP(i, H * W) pow3.emplace_back(pow3.back() * 3);
    vector<vector<int>> ans_board;

    vector<char> kind = {'.', '\\', '/'};
    REP(state, all_state) {
      vector<vector<int>> board(N, vector<int>(N, 0));

      REP(i, H) REP(j, W) {
        board[i + 1][j + 1] = state / pow3[i * W + j] % 3;
      }

      /*
        for (int i = N - 2; i >= 0; i--) {
        REP(j, N) {
        //cout << i << ' ' << j << endl;
        cout << kind[board[i][j]];
        }
        cout << endl;
        }
      */

      int flag = false;
      REP(r, N) REP(c, N - 1) {
        //cout << r << ' ' << c << endl;
        if (board[r][c] == 1 and board[r][c + 1] == 2) {
          flag = true;
        }
      }
      if (flag) continue;
      vector<int> balls(N, 0);
      for (int i = 0; i < N; i++) {
        //cout << i << endl;
        int prev = -1;
        int r = N - 1, c = i;
        while (r > 0) {
          if (board[r][c] == 0) {
            r--;
            prev = 0;
          } else if (board[r][c] == 1) {
            if (prev == 1) {
              r--;
            } else {
              c++;
            }
            prev = 1;
          } else {
            if (prev == 2) {
              r--;
            } else {
              c--;
            }
            prev = 2;
          }
        }
        balls[c]++;
      }
      flag = true;
      for (int i = 0; i < N; i++) flag &= balls[i] == B[i];
      if (flag) {
        int cnt = N;
        for (int i = N - 1; i >= 0; i--) {
          if (all_of(board[i].begin(), board[i].end(), [](int x) { return x == 0; })) {
            cnt--;
          } else {
            break;
          }
        }
        cnt = max(1, cnt);
        if (cnt < ans) {
          ans = cnt;
          ans_board = board;
        }
      }
    }
    if (ans == N + 1) {
      cout << "Case #" << testcase + 1 << ": IMPOSSIBLE" << endl;
    } else {
      cout << "Case #" << testcase + 1 << ": " << ans << endl;
      for (int i = ans - 1; i >= 0; i--) {
        REP(j, N) cout << kind[ans_board[i][j]];
        cout << endl;
      }
    }
  }

  return 0;
}
