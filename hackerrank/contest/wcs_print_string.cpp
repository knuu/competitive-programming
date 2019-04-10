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

  int T; cin >> T;
  REP(_, T) {
    int N, A, B; cin >> N >> A >> B;
    string S; cin >> S;

    vector<int> prev(N);
    string p, n;
    for (int i = 0, l = 0; i < N; i++) {
      while (l < i+1 and S.substr(0, l).find(S.substr(l, i - l + 1)) == string::npos) l++;
      prev[i] = l == i+1 ? -1 : l-1;
    }

    vector<int> dp(N+1);
    dp[0] = 0;
    REP(i, N) {
      if (prev[i] == -1) {
	dp[i+1] = dp[i] + A;
      } else {
	dp[i+1] = min(dp[i] + A, dp[prev[i] + 1] + B);
      }
    }
    //REP(i, N+1) cout << dp[i] << (i == N ? '\n' : ' ');
    cout << dp[N] << endl;
  }
  return 0;
}
