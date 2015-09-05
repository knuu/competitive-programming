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

int A, B;
int a[1024], b[1024];
int dp[1024][1024];
//function<int(int, int)> choice[2] =
//  {[](int a, int b) -> int { return max(a, b); },
//   [](int a, int b) -> int { return min(a, b); }};

int main() {
  scanf("%d %d", &A, &B);
  REP(i, A) scanf("%d", a+i);
  REP(i, B) scanf("%d", b+i);
  
  for (int aa = A; aa >= 0; aa--) {
    for (int bb = B; bb >= 0; bb--) {
      int turn = (aa+bb) % 2;
      int sig = turn ? -1 : 1;
      if (aa < A && bb < B) {
	if (turn) {
	  dp[aa][bb] = min(dp[aa][bb+1] + sig * b[bb],
			   dp[aa+1][bb] + sig * a[aa]);
	} else {
	  dp[aa][bb] = max(dp[aa][bb+1] + sig * b[bb],
			   dp[aa+1][bb] + sig * a[aa]);
	}
	  
      } else if (aa < A) {
	dp[aa][bb] = dp[aa+1][bb] + sig * a[aa];
      } else if (bb < B) {
	dp[aa][bb] = dp[aa][bb+1] + sig * b[bb];
      }
    }
  }

  //  REP(i, A+1) REP(j, B+1) cout << dp[i][j] << (j==B ? '\n' : ' ');
  printf("%d\n", (accumulate(a, a+A, 0) + accumulate(b, b+B, 0) + dp[0][0])/2);
      
  return 0;
}
