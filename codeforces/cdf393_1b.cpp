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

const ll INF = 1e18;

int main() {
  int N; scanf("%d", &N);
  vector<int> T(N + 1);
  T[0] = 0;
  REP(i, N) scanf("%d", &T[i+1]);

  vector<ll> dp(N + 1, INF);
  dp[0] = 0;
  REP(i, N) {
    dp[i+1] = dp[i] + 20;
    int ub1 = upper_bound(ALL(T), T[i+1] - 90) - T.begin();
    if (T[i+1] < T[ub1] + 90) ub1 = max(0, ub1 - 1);
    dp[i+1] = min(dp[i+1], dp[ub1] + 50);
    int ub2 = upper_bound(ALL(T), T[i+1] - 1440) - T.begin();
    if (T[i+1] < T[ub2] + 1440) ub2 = max(0, ub2 - 1);
    dp[i+1] = min(dp[i+1], dp[ub2] + 120);
  }
  vector<ll> ans(N);
  ll now = dp[N];
  for (int i = N; i > 0; i--) {
    now = min(now, dp[i]);
    ans[i-1] = max<ll>(0, now - dp[i-1]);
  }

  REP(i, N) printf("%lld\n", ans[i]);
  return 0;
}
