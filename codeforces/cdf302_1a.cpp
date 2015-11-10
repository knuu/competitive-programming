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

ll dp[512][512];
int a[500];

int main() {

  int N, M, B, m;
  ll mod;
  scanf("%d %d %d %d", &N, &M, &B, &m); mod = (ll)m;
  REP(i, N) scanf("%d", a+i);

  dp[0][0] = 1;
  REP(i, N) REP(r, M) FOR(b, a[i], B+1) {
    dp[r+1][b] += dp[r][b-a[i]];
    dp[r+1][b] %= mod;
  }
  
  ll ans = 0;
  REP(i, B+1) {
    ans += dp[M][i];
    ans %= mod;
  }
  printf("%d\n", (int)ans);
  return 0;
}
