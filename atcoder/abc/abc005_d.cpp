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
  int N; cin >> N;
  vector<vector<int>> board(N+1, vector<int>(N+1, 0));
  REP(i, N) REP(j, N) cin >> board[i+1][j+1];
  REP(i, N+1) REP(j, N) board[i][j+1] += board[i][j];
  REP(i, N) REP(j, N+1) board[i+1][j] += board[i][j];
  vector<int> dp(N*N+1, 0);
  REP(r1, N) REP(c1, N) FOR(r2, r1+1, N+1) FOR(c2, c1+1, N+1) {
    int S = (r2-r1) * (c2-c1);
    dp[S] = max(dp[S], board[r2][c2] - board[r2][c1] - board[r1][c2] + board[r1][c1]);
  }
  REP(i, N*N) dp[i+1] = max(dp[i], dp[i+1]);

  int Q; cin >> Q;
  REP(i, Q) {
    int p; cin >> p;
    cout << dp[p] << endl;
  }
  return 0;
}
