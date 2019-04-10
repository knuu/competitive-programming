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

const ll mod = 1e9 + 7;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<vector<int>> mat(N, vector<int>(N)); REP(i, N) REP(j, N) cin >> mat[i][j];
  vector<ll> dp(1 << N);
  dp[0] = 1;
  REP(bit, (1 << N) - 1) {
    int man = __builtin_popcount(bit);
    dp[bit] %= mod;
    REP(woman, N) {
      if (mat[man][woman] and (bit >> woman & 1) == 0) {
        dp[bit | (1 << woman)] += dp[bit];
      }
    }
  }
  cout << dp[(1 << N) - 1] % mod << endl;

  return 0;
}
