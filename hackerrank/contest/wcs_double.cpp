#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
//typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

vector<int> edge[200010];
int l, r;

inline int dfs(int v, int par) {
  if (v < l or r < v) return 0;
  int ret = 1;
  for (int c : edge[v]) {
    if (c != par) ret += dfs(c, v);
  }
  return ret;
}

int main() {
  int N; scanf("%d", &N);
  REP(i, N-1) {
    int a, b; scanf("%d %d", &a, &b); a--, b--;
    edge[a].push_back(b), edge[b].push_back(a);
  }
  int ans = 0;
  REP(i, N) FOR(j, i, N) {
    l = i, r = j;
    if (j - i + 1 == dfs(i, -1)) {
      printf("%d %d\n", i+1, j+1);
      ans++;
    }
  }
  printf("%d\n", ans);

  return 0;
}
