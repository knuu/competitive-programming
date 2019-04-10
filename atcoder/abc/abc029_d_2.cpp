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

int dp[11][11][2];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string N; cin >> N;
  int L = N.size();
  dp[0][0][0] = 1;
  REP(len, L) {
    REP(cnt, L + 1) {
      REP(cond, 2) {
        if (cond == 1) {
          REP(i, 10) {
            if (i == 1) {
              dp[len + 1][cnt + 1][1] += dp[len][cnt][1];
            } else {
              dp[len + 1][cnt][1] += dp[len][cnt][1];
            }
          }
        } else {
          REP(i, N[len] - '0') {
            if (i == 1) {
              dp[len + 1][cnt + 1][1] += dp[len][cnt][0];
            } else {
              dp[len + 1][cnt][1] += dp[len][cnt][0];
            }
          }
          if (N[len] - '0' == 1) {
            dp[len + 1][cnt + 1][0] += dp[len][cnt][0];
          } else {
            dp[len + 1][cnt][0] += dp[len][cnt][0];
          }
        }
      }
    }
  }
  int ans = 0;
  REP(i, L + 1) REP(j, 2) ans += dp[L][i][j] * i;
  cout << ans << endl;
  return 0;
}
