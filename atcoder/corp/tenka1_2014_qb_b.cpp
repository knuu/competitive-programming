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
  string S; cin >> S;
  vector<string> T(N);
  REP(i, N) cin >> T[i];

  const ll mod = 1e9+7;
  vector<ll> dp((int)S.size() + 1, 0);
  dp[0] = 1;
  REP(s, S.size()) {
    if (s and dp[s] == 0) continue;
    REP(i, N) {
      int flag = true;
      if (S.size() - s < T[i].size()) continue;
      REP(j, T[i].size()) {
	if (S[s+j] != T[i][j]) {
	  flag = false;
	  break;
	}
      }
      if (flag) {
	dp[s+T[i].size()] += dp[s];
	dp[s+T[i].size()] %= mod;
      }
    }
  }
  cout << dp[S.size()] << endl;
  return 0;
}
