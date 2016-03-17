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

const ll mod = 1000000007;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, M; cin >> N >> M;
  string s; cin >> s;
  int L = N-M;
  vector<vector<ll>> dp(L+1, vector<ll>(L+1, 0));
  dp[0][0] = 1;

  REP(i, L) REP(j, L+1) {
    if (j < L) {
      dp[i+1][j+1] += dp[i][j];
      dp[i+1][j+1] %= mod;
    }
    if (j > 0) {
      dp[i+1][j-1] +=dp[i][j];
      dp[i+1][j-1] %= mod;
    }
  }

  int lo = INT_MAX, cnt = 0;
  REP(i, M) {
    if (s[i] == '(') {
      cnt++;
    } else {
      cnt--;
      lo = min(lo, cnt);
    }
  }
  lo = -lo;

  ll ans = 0;
  REP(i, L+1) REP(j, L+1) {
    if (j >= lo and 0 <= j+cnt and j+cnt <= L) {
      ans += dp[i][j] * dp[L-i][j+cnt];
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
