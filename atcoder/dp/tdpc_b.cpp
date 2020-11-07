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

#define INF (int)1e7

int A, B;
int a[1024], b[1024];
int dp[1024][1024];
function<int(int, int)> choice[2] =
  {[](int a, int b) -> int { return max(a, b); },
   [](int a, int b) -> int { return min(a, b); }};

int dfs(int aa, int bb) {
  if (aa + bb == A + B) return 0;
  if (dp[aa][bb] != INF) return dp[aa][bb];
  
  int ret = (aa + bb) % 2 == 0 ? -INF : INF;
  int turn = (aa + bb) % 2 == 0 ? 1 : -1; 
  if (aa < A)
    ret = choice[(aa + bb) % 2](ret, turn * a[aa] + dfs(aa+1, bb));
  if (bb < B)
    ret = choice[(aa + bb) % 2](ret, turn * b[bb] + dfs(aa, bb+1));

  return dp[aa][bb] = ret;
}

int main() {
  scanf("%d %d", &A, &B);
  REP(i, A) scanf("%d", a+i);
  REP(i, B) scanf("%d", b+i);
  REP(i, A+1) REP(j, B+1) dp[i][j] = INF;
  
  printf("%d\n", (accumulate(a, a+A, 0) + accumulate(b, b+B, 0) + dfs(0, 0))/2);

  REP(i, A+1) REP(j, B+1) cout << dp[i][j] << (j==B ? '\n' : ' ');
  return 0;
}
