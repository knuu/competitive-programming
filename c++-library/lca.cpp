#define MAX_V 100010
#define MAX_LOG_V 16

struct LCA{
  vector<int> edge[MAX_V];
  int parent[MAX_LOG_V][MAX_V];
  int depth[MAX_V];
  int root;

  LCA(int r) {
    root = r;
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
