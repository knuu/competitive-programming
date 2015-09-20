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

int dp[310];
int N, ng[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin >> N;
  REP(i, 3) cin >> ng[i];
  fill(dp, dp+N+1, 101);

  REP(i, 3) {
    if (ng[i] == N) {
      cout << "NO" << endl;
      return 0;
    }
  }

  dp[N] = 0;
  for (int i = N; i >= 0; i--) {
    if (i == ng[0] || i == ng[1] || i == ng[2]) continue;
    REP(j, 3) {
      if (i - (j+1) >= 0) {
	dp[i - (j+1)] = min(dp[i - (j+1)], dp[i]+1);
      }
    }
  }
  
  cout << (dp[0] <= 100 ? "YES" : "NO") << endl;
      
  return 0;
}
