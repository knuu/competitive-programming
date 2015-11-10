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

int dp[2][512][521];
int a[500];

int main() {
  int N, M, B, mod;
  scanf("%d %d %d %d", &N, &M, &B, &mod);
  REP(i, N) scanf("%d", a+i);

  dp[0][0][0] = 1;
  REP(i, N) {
    int now = i%2, next = i^1;
    REP(j, M) REP(k, B+1) dp[next][j][k] = 0;
    REP(j, M) REP(k, B+1) {
      if (!dp[now][j][k] || k + a[i] > B) continue;
      dp[next][j+1][k+a[i]] += dp[now][j][k];
      dp[next][j+1][k+a[i]] %= mod;
    }
  }
  int ans = 0;
  REP(i, B+1) {
    ans += dp[N%2][M][i];
    ans %= mod;
  }
  printf("%d\n", ans);
  return 0;
}
