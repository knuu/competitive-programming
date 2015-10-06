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
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

int dp[512][512];

int dfs(int rock, int can_take) {
  if (rock <= 0) return false;
  if (dp[rock][can_take] != -1) return dp[rock][can_take];

  int result = 0;
  REP(i, can_take) {
    if (!dfs(rock - (i + 1), i + 2)) result = 1;
  }
  return dp[rock][can_take] = result;
}  

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, P;
  cin >> N >> P;
  memset(dp, -1, sizeof(dp));
  cout << (dfs(N, P) ? "first" : "second") << endl;
  return 0;
}
