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

int R[1024];
double dp[16][1024];

int main() {
  int K;
  scanf("%d", &K);
  int N = 1<<K;
  
  REP(i, N) {
    scanf("%d", R+i);
    dp[0][i] = 1.0;
  }

  
  for (int k = 0; k < K; k++) {
    REP(i, N) {
      dp[k+1][i] = 0.0;
      int cnt = i>>(k+1), left = cnt<<(k+1), right = (cnt+1)<<(k+1);
      int mid = (left + right)>>1;
      if (i < mid) {
	FOR(j, mid, right) {
	  dp[k+1][i] += dp[k][j] / (1.0 + pow(10.0, (R[j]-R[i]) / 400.0));
	}
      } else {
	FOR(j, left, mid) {
	  dp[k+1][i] += dp[k][j] / (1.0 + pow(10.0, (R[j]-R[i]) / 400.0));
	}
      }
      dp[k+1][i] *= dp[k][i];
    }
  }

  REP(i, N) printf("%.12lf\n", dp[K][i]);
  return 0;
}
