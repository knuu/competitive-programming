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

bool dp[5010];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int weight[128];
  REP(i, N) cin >> weight[i];
  int sum = accumulate(weight, weight + N, 0);
  if (sum & 1) {
    cout << "impossible" << endl;
    return 0;
  }
  fill(dp, dp + sum/2 + 1, false);
  dp[0] = true;
  REP(i, N) {
    for (int j = sum/2; j >= 0; j--) {
      if (dp[j] && j + weight[i] <= sum/2)
	dp[j + weight[i]] = true;
    }
  }
  cout << (dp[sum/2] ? "possible" : "impossible") << endl;
  return 0;
}
