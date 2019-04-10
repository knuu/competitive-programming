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

int N, M;
ll board[2000][2000];

ll calc_pairs() {
  vector<vector<ll>> acc_col(N, vector<ll>(M, 0));
  REP(i, N) REP(j, M) acc_col[i][j] = board[i][j];
  REP(j, M) {
    for (int i = N - 2; i >= 0; i--) {
      if (board[i][j] == 1) acc_col[i][j] += acc_col[i + 1][j];
    }
    REP(i, N) if (board[i][j] == 1) acc_col[i][j]--;
  }
  //REP(i, N) REP(j, M) cout << acc_col[i][j] << (j == M - 1 ? '\n' : ' ');

  vector<vector<ll>> acc_row(N, vector<ll>(M, 0));
  REP(i, N) {
    for (int j = M - 2; j >= 0; j--) {
      if (board[i][j] == 1) {
        acc_row[i][j] = acc_row[i][j + 1] + acc_col[i][j + 1];
      }
    }
  }
  //REP(i, N) REP(j, M) cout << acc_row[i][j] << (j == M - 1 ? '\n' : ' ');

  ll ret = 0;
  REP(i, N) REP(j, M) {
    if (board[i][j] == 1) ret += acc_row[i][j];
  }
  //cout << ret << endl;
  return ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  vector<vector<int>> origin_board(N, vector<int>(M));
  REP(i, N) {
    string row; cin >> row;
    REP(j, M) origin_board[i][j] = row[j] == '#' ? 0 : 1;
  }

  ll ans = 0;

  REP(i, N) REP(j, M) board[i][j] = origin_board[i][j];
  //REP(i, N) REP(j, M) cout << board[i][j] << (j == M - 1 ? '\n' : ' ');
  ans += calc_pairs();
  //cout << ans << endl;

  for (int j = 0, r = 0; j < M; j++, r++) {
    for (int i = N - 1, c = 0; i >= 0; i--, c++) {
      board[r][c] = origin_board[i][j];
    }
  }
  swap(N, M);
  ans += calc_pairs();
  swap(N, M);

  for (int i = N - 1, r = 0; i >= 0; i--, r++) {
    for (int j = M - 1, c = 0; j >= 0; j--, c++) {
      board[r][c] = origin_board[i][j];
    }
  }

  ans += calc_pairs();

  for (int j = M - 1, r = 0; j >= 0; j--, r++) {
    for (int i = 0, c = 0; i < N; i++, c++) {
      board[r][c] = origin_board[i][j];
    }
  }

  swap(N, M);
  ans += calc_pairs();

  cout << ans << endl;

  return 0;
}
