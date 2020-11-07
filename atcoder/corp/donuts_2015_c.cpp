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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N; cin >> N;
  vector<int> H(N+1); REP(i, N) cin >> H[i+1];
  H[0] = 1000001;

  vector<vector<int>> dp(N+1, vector<int>(2, 0));
  REP(i, N) {
    int l = i;
    while (H[i+1] > H[l]) l = dp[l][1];
    dp[i+1][0] = dp[l][0] + 1;
    dp[i+1][1] = l;
  }
  REP(i, N) cout << dp[i][0] << endl;
  return 0;
}
