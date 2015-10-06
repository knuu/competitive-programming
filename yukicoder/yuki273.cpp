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

bool par[64][64];
int dp[64][64];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string S;
  cin >> S;

  int N = S.size();
  REP(i, N) REP(j, N) par[i][j] = false;
  REP(i, N) {
    for (int l = i, r = i; l >= 0 && r < N && S[l] == S[r]; l--, r++) {
      par[l][r] = true;
    }
    for (int l = i, r = i+1; l >= 0 && r < N && S[l] == S[r]; l--, r++) {
      par[l][r] = true;
    }
  }
  par[0][N-1] = false;

  REP(i, N) {
    FOR(j, i, N) {
      if (par[i][j]) {
	dp[j+1][j+1] = max(dp[j+1][j+1], j - i + 1);
      }
    }
    dp[i+1][i+1] = max(dp[i+1][i+1], dp[i][i]);
  }
  cout << dp[N][N] << endl;  
  return 0;
}
