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

int color[200010];
int dp[2][2];

int main() {
  int N;
  cin >> N;
  REP(i, N) scanf("%d", &color[i]);
  FOR(i, N, 2*N) color[i] = color[i-N];

  dp[0][0] = dp[0][1] = 1;
  REP(i, 2*N-1) {
    dp[(i+1)%2][1] = (color[i] == color[i+1]) * dp[i%2][1] + 1;
    dp[(i+1)%2][0] = max(dp[i%2][0], dp[(i+1)%2][1]);
  }

  
  if (dp[1][0] < N) {
    cout << (dp[1][0] - 1) / 2 + 1 << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
