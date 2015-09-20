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
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

#define INF 1300500000

int dp[2][256];
int sample[20010];


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (1) {
    int N, M, code[16];
    cin >> N >> M;
    if (N == 0 && M == 0) break;
    REP(i, M) cin >> code[i];
    REP(i, N) cin >> sample[i];

    fill(dp[0], dp[0]+256, -1);
    dp[0][128] = 0;

    REP(i, N) {
      fill(dp[(i+1)%2], dp[(i+1)%2]+256, -1);
      REP(j, 256) {
	if (dp[i%2][j] == -1) continue;
	REP(k, M) {
	  int next = max(0, min(255, j + code[k]));
	  int diff = sample[i] - next;
	  if (dp[(i+1)%2][next] == -1 || dp[i%2][j] + diff * diff < dp[(i+1)%2][next]) {
	  dp[(i+1)%2][next] = dp[i%2][j] + diff * diff;
	  }
	}
      }
    }
    int ans = -1;
    REP(i, 256) {
      if (ans == -1 || (dp[N%2][i] != -1 && dp[N%2][i] < ans))
	ans = dp[N%2][i];
    }
    cout << ans << endl;
  }

  return 0;
}
