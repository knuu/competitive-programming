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

bool dp[1024], dp2[1024];
int A[1000010];

int main() {

  int N, M;
  scanf("%d %d", &N, &M);
  if (N > M) {
    printf("YES\n");
    return 0;
  }
  REP(i, N) {
    scanf("%d", A+i);
    A[i] %= M;
  }

  memset(dp, false, sizeof(dp));

  for (int i = 0; i < N && !dp[0]; i++) {
    memcpy(dp2, dp, sizeof(dp));
    
    if (!dp2[A[i]]) dp2[A[i]] = true;

    REP(j, M) {
      if (dp[j] && !dp[(j+A[i])%M])
	dp2[(j+A[i])%M] = true;
    }
    memcpy(dp, dp2, sizeof(dp2));
  }
  printf(dp[0] ? "YES\n" : "NO\n");
  
  return 0;
}
