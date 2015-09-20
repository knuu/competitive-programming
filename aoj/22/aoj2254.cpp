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

#define INF 10000000

int dp[1<<16];
int tool[16][17];
int N;

int rec(int S) {
  if (dp[S] != -1)
    return dp[S];
  if (S == (1<<N)-1)
    return dp[S] = 0;

  int ret = INF;
  REP(i, N) {
    if (!(S >> i & 1)) {
      int next = tool[i][0];
      REP(j, N) {
	if (S >> j & 1) next = min(next, tool[i][j+1]);
      }
      ret = min(ret, rec(S | 1 << i) + next);
    }
  }
  return dp[S] = ret;
}  

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (1) {
    cin >> N;
    if (N == 0) break;

    REP(i, N) REP(j, N+1) cin >> tool[i][j];
    memset(dp, -1, sizeof(dp));
    cout << rec(0) << endl;
  }  
  return 0;
}
