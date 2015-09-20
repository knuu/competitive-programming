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

int dp[128][128][128];
int N, ng[3];


int dfs(int c1, int c2, int c3) {
  if (c1 + c2 + c3 > 100) return 0;
  int now = N - (c1 + c2 * 2 + c3 * 3);

  if (now < 0) return 0;
  REP(i, 3) {
    if (now == ng[i]) return 0;
  }
  if (now == 0) return 1;
  if (dp[c1][c2][c3] != -1) return dp[c1][c2][c3];

  int ret = 0;
  if (dfs(c1+1, c2, c3)) ret = 1;
  if (dfs(c1, c2+1, c3)) ret = 1;
  if (dfs(c1, c2, c3+1)) ret = 1;

  return dp[c1][c2][c3] = ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> N;
  REP(i, 3) cin >> ng[i];
  REP(i, 101) REP(j, 101) REP(k, 101) dp[i][j][k] = -1;
  cout << (dfs(0, 0, 0) ? "YES" : "NO") << endl;
  return 0;
}
