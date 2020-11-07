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
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

struct LowestCommonAncestor {
  int V, log_V;
  std::vector<std::vector<int>> edge;

  std::vector<std::vector<int>> parent;
  std::vector<int> depth;

  LowestCommonAncestor(int V) : V(V), log_V(std::ceil(std::log2(V)) + 1) {
    edge.resize(V);
    parent.resize(log_V);
    for (int i = 0; i < log_V; i++) parent[i].resize(V);
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

  void build(int root = 0) {
    dfs(root, -1, 0);
    for (int k = 0; k + 1 < log_V; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0) {
          parent[k + 1][v] = -1;
        } else {
          parent[k + 1][v] = parent[k][parent[k][v]];
        }
      }
    }
  }

  int run(int u, int v) {
    if (depth[u] > depth[v]) std::swap(u, v);
    for (int k = 0; k < log_V; k++) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if (u == v) return u;

    for (int k = log_V - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }

  // cnt 個上の親を取得する
  int get_cntup_node(int v, int cnt) {
    if (cnt <= 0) return v;
    for (int k = log_V - 1; k >= 0; k--) {
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

  int root = 0;
  REP(i, N) {
    int p; cin >> p; p--;
    if (p >= 0) {
      lca.add_edge(p, i);
    } else {
      root = i;
    }
  }

  lca.build(root);
  int Q; cin >> Q;
  REP(q, Q) {
    int a, b; cin >> a >> b; a--, b--;
    int v = lca.run(a, b);
    cout << (v == b ? "Yes" : "No") << endl;
  }

  return 0;
}
