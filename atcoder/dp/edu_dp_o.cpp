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

  int N; cin >> N;
  vector<vector<int>> A(N, vector<int>(N));
  REP(i, N) REP(j, N) cin >> A[i][j];
  const ll mod = 1e9+7;
  vector<ll> dp(1 << N);
  dp[0] = 1;
  REP(state, 1 << N) {
    int i = __builtin_popcount(state);
    REP(j, N) {
      if ((state >> j & 1) == 0 and A[i][j]) {
        dp[state | (1 << j)] += dp[state];
        dp[state | (1 << j)] %= mod;
      }
    }
  }

  cout << dp[(1 << N) - 1] << endl;
  return 0;
}
