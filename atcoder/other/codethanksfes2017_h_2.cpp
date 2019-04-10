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


struct DisjointSet {
  vector<int> parent, rank;

  DisjointSet(int N) {
    parent.resize(N), rank.resize(N, 0);
    for (int i = 0; i < N; i++) parent[i] = i;
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = find(parent[x]);
    }
  }

  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return ;
    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }
};

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
    if (cnt <= 0) return v;
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
  //cin.tie(0);
  //ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  DisjointSet uf(N);
  vector<int> q_num(N, -1);
  int root = N;
  LowestCommonAncestor lca(N + 1);

  REP(i, M) {
    int a, b; cin >> a >> b; a--, b--;
    if (not uf.same(a, b)) {
      a = uf.find(a), b = uf.find(b);
      uf.unite(a, b);
      lca.add_edge(a, b);
      if (uf.find(a) == a) {
        q_num[b] = i + 1;
      } else {
        q_num[a] = i + 1;
      }
    }
  }

  REP(i, N) if (uf.parent[i] == i) lca.add_edge(i, root);
  lca.init(root);

  int Q; cin >> Q;
  REP(i, Q) {
    int x, y; cin >> x >> y; x--, y--;
    if (not uf.same(x, y)) {
      cout << -1 << endl;
    } else {
      int anc = lca.run(x, y);
      int u_cnt = lca.depth[x] - lca.depth[anc];
      int v_cnt = lca.depth[y] - lca.depth[anc];
      int v1 = lca.get_cntup_node(x, max(0, u_cnt - 1));
      int v2 = lca.get_cntup_node(y, max(0, v_cnt - 1));
      if (u_cnt == 0) {
        cout << q_num[v2] << endl;
      } else if (v_cnt == 0) {
        cout << q_num[v1] << endl;
      } else {
        cout << max(q_num[v1], q_num[v2]) << endl;
      }
    }
  }

  return 0;
}
