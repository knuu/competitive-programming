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

struct LowestCommonAncestor {

  int V, MAX_LOG_V;
  vector<vector<int>> edge;

  vector<vector<int>> parent;
  vector<int> depth;

  LowestCommonAncestor(int V, int MAX_LOG_V = 17) : V(V), MAX_LOG_V(MAX_LOG_V) {
    edge.resize(V);
    parent.resize(MAX_LOG_V);
    REP(i, MAX_LOG_V) parent[i].resize(V);
    depth.resize(V);
  }

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

  void init(int root = 0) {
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

  int run(int u, int v) {
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

  int get_cntup_node(int v, int cnt) {
    for (int k = MAX_LOG_V - 1; k >= 0; k--) {
      if (cnt >> k & 1) {
        v = parent[k][v];
      }
    }
    return v;
  }
};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  LowestCommonAncestor lca(N);
  REP(i, N) {
    int K; cin >> K;
    REP(_, K) {
      int c; cin >> c;
      lca.add_edge(i, c);
    }
  }

  lca.init();

  int Q; cin >> Q;
  REP(i, Q) {
    int u, v; cin >> u >> v;
    int anc = lca.run(u, v);
    cout << anc << endl;
  }

  return 0;
}
