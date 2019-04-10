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
    string S_final; cin >> S_final;

    map<P, int> memo;
    REP(i, N) {
      FOR(j, i+1, N) {
	int l = i, r = j;
	while (r < N and l < j and S_final[l] == S_final[r]) {
	  memo[P(j, r-j+1)] = 1;
	  l++, r++;
	}
	//cout << '(' << i << ',' << j << "):" << l << ' ' << r << endl;
      }
    }
    for (auto p : memo) cout << '(' << p.first.first << ',' << p.first.second << ") ";
    cout << endl;

    vector<int> dp(N+1, 1e9);
    dp[0] = 0;
    REP(i, N) {
      dp[i+1] = min(dp[i+1], dp[i] + A);
      for (int j = 1; j <= i and i + j <= N; j++) {
	if (memo[P(i, j)]) {
	  dp[i+j] = min(dp[i+j], dp[i] + B);
	}
      }
    }
    REP(i, N+1) cout << dp[i] << (i == N ? '\n' : ' ');
    cout << dp[N] << endl;
  }
  return 0;
}
