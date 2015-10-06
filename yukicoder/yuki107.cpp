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

const int MAX_N = 16;

int N;
int dp[1<<MAX_N];
int monster[16];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  REP(i, N) cin >> monster[i];

  dp[0] = 100;
  REP(state, 1<<N) {
    if (!dp[state]) continue;
    int level = 1;
    REP(i, N) {
      if ((state >> i & 1) && monster[i] < 0) level++;
    }
    
    REP(i, N) {
      if (!(state >> i & 1)) {
	int next_level = level + (monster[i] < 0 ? 1 : 0);
	dp[state | 1 << i] = max(dp[state | 1 << i],
				 min(100 * next_level, dp[state] + monster[i]));
      }
    }
  }
  cout << dp[(1<<N)-1] << endl;
  return 0;
}
