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
  vector<bool> dp(N * 100 + 1, false);
  dp[0] = true;

  vector<int> P(N); REP(i, N) cin >> P[i];

  for (int p : P) {
    for (int i = N * 100 - p; i >= 0; i--) {
      if (dp[i]) dp[i + p] = true;
    }
  }

  cout << accumulate(ALL(dp), 0) << endl;

  return 0;
}
