#include <iostream>
#include <cassert>
using namespace std;
typedef long long int ll;
//typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define rep(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

int N;
ll adj[40];

int dfs(int v, ll S) {
  //cout << v << ':'; REP(i, N) cout << (S >> i & 1); cout << endl;
  assert((S >> v & 1) == 1 or __builtin_popcountll(S) == 0);
  if (__builtin_popcountll(S) == 0) return 0;
  S &= ~(1LL << v);
  ll tmp_state = S & ~adj[v];
  int ret = 1 + dfs(__builtin_ctzll(tmp_state), tmp_state);
  return __builtin_popcountll(adj[v]) <= 1 ? ret : max(ret, dfs(__builtin_ctzll(S), S));
}

int main() {
  int M; scanf("%d %d", &N, &M);
  REP(i, M) {
    int a, b; scanf("%d %d", &a, &b); a--, b--;
    adj[a] |= 1LL << b;
    adj[b] |= 1LL << a;
  }

  printf("%d\n", dfs(0, (1LL << N) - 1LL));

  return 0;
}
