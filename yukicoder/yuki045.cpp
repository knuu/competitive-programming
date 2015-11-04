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

int dp[1024];
int V[1024];

int main() {
  int N;
  scanf("%d", &N);
  REP(i, N) scanf("%d", V+i);
  int sushi = 0;
  REP(i, N) {
    dp[i+1] = max(dp[i], sushi + V[i]);
    sushi = max(sushi, dp[i]);
  }
  printf("%d\n", dp[N]);
  return 0;
}
