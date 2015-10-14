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

double dp[128][64][64][64];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  ll D;
  cin >> N >> D;

  int cnt2 = 0, cnt3 = 0, cnt5 = 0;

  while (D % 2 == 0) D /= 2, cnt2++;
  while (D % 3 == 0) D /= 3, cnt3++;
  while (D % 5 == 0) D /= 5, cnt5++;

  if (D != 1) {
    cout << 0 << endl;
    return 0;
  }

  dp[0][0][0][0] = 1.0;

  REP(i, N) {
    REP(c2, cnt2 + 1) REP(c3, cnt3 + 1) REP(c5, cnt5 + 1) {
      if (!dp[i][c2][c3][c5]) continue;
      FOR(d, 1, 7) {
	if (d == 1) dp[i+1][c2][c3][c5] += dp[i][c2][c3][c5] / 6.0;
	if (d == 2) dp[i+1][min(c2+1, cnt2)][c3][c5] += dp[i][c2][c3][c5] / 6.0;
	if (d == 3) dp[i+1][c2][min(c3+1, cnt3)][c5] += dp[i][c2][c3][c5] / 6.0;
	if (d == 4) dp[i+1][min(c2+2, cnt2)][c3][c5] += dp[i][c2][c3][c5] / 6.0;
	if (d == 5) dp[i+1][c2][c3][min(c5+1, cnt5)] += dp[i][c2][c3][c5] / 6.0;
	if (d == 6) dp[i+1][min(c2+1, cnt2)][min(c3+1, cnt3)][c5] += dp[i][c2][c3][c5] / 6.0;
      }
    }
  }
  cout << setprecision(10) << dp[N][cnt2][cnt3][cnt5] << endl;
  return 0;
}
