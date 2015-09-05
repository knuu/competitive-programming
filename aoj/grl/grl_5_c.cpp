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

#define MAX_V 100010
#define MAX_LOG_V 20

vector<int> edge[MAX_V];
int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];

struct LCA{
  int root;

  LCA(int r): root(r){}

  void add_edge(int a, int b) {
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  
  void dfs(int v, int par, int dep) {
    parent[0][v] = par;
    depth[v] = dep;
    for (auto child : edge[v]) {
      if (child != par) dfs(child, v, dep + 1);
    }
  }

  void init(int V) {
    dfs(root, -1, 0);
    for (int k = 0; k + 1 < MAX_LOG_V; k++) {
      for (int v = 0; v < V; v++) {
	if (parent[k][v] < 0) {
	  parent[k+1][v] = -1;
	} else {
	  parent[k+1][v] = parent[k][parent[k][v]];
	}
      }
    }
  }

  int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < MAX_LOG_V; k++) {
      if ((depth[v] - depth[u]) >> k & 1) {
	v = parent[k][v];
      }
    }
    if (u == v) return u;
    for (int k = MAX_LOG_V - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
	u = parent[k][u];
	v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};

int main() {
  int N;
  LCA lca(0);
  
  scanf("%d", &N);
  REP(i, N) {
    int k;
    scanf("%d", &k);
    REP(j, k) {
      int c;
      scanf("%d", &c);
      lca.add_edge(i, c);
    }
  }
  lca.init(N);
  int Q;
  scanf("%d", &Q);
  REP(i, Q) {
    int u, v;
    scanf("%d %d", &u, &v);
    printf("%d\n", lca.lca(u, v));
  }
  return 0;
}
