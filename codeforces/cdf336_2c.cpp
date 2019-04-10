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

P beacons[100010];
int dp[100010];

int main() {
  int N; cin >> N;
  REP(i, N) {
    int a, b; cin >> a >> b;
    beacons[i] = P(a, b);
  }
  sort(beacons, beacons + N);
  dp[0] = 0;
  FOR(i, 1, N) {
    int left_pos = beacons[i].first - beacons[i].second;
    int left = lower_bound(beacons, beacons + N, P(left_pos, 0)) - beacons;
    dp[i] = i - left + dp[max(0, left - 1)];
  }
  // REP(i, N) cout << dp[i] << (i == N-1 ? '\n' : ' ');

  int ans = N;
  REP(i, N) {
    ans = min(ans, dp[i] + N - i - 1);
  }
  cout << ans << endl;
  return 0;
}
