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

vector<vector<tuple<int, int, int>>> edges;
vector<tuple<int, int, int, int>> queries;
vector<int> color_cnt, color_sum, tree_sum;
vector<vector<int>> need_info;
map<pair<int, int>, pair<int, int>> info;

void dfs(int v, int par) {
  for (int color : need_info[v]) {
    info[make_pair(v, color)] = make_pair(color_cnt[color], color_sum[color]);
  }

  for (auto child : edges[v]) {
    int next_v, color, w; tie(next_v, color, w) = child;
    if (next_v == par) continue;
    color_cnt[color]++;
    color_sum[color] += w;
    tree_sum[next_v] += tree_sum[v] + w;
    dfs(next_v, v);
    color_cnt[color]--;
    color_sum[color] -= w;
  }
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, Q; cin >> N >> Q;
  edges.resize(N);
  color_cnt.resize(N, 0), color_sum.resize(N, 0), tree_sum.resize(N, 0);
  need_info.resize(N);

  LowestCommonAncestor lca(N);

  REP(i, N-1) {
    int a, b, c, d; cin >> a >> b >> c >> d; a--, b--, c--;
    edges[a].emplace_back(b, c, d);
    edges[b].emplace_back(a, c, d);
    lca.add_edge(a, b);
  }

  lca.build();

  REP(i, Q) {
    int x, y, u, v; cin >> x >> y >> u >> v; x--, u--, v--;
    queries.emplace_back(x, y, u, v);
    int par = lca.run(u, v);
    need_info[u].emplace_back(x);
    need_info[v].emplace_back(x);
    need_info[par].emplace_back(x);
  }

  dfs(0, -1);

  for (auto query : queries) {
    int x, y, u, v; tie(x, y, u, v) = query;
    int par = lca.run(u, v);
    int u_cnt, u_sum; tie(u_cnt, u_sum) = info[make_pair(u, x)];
    int v_cnt, v_sum; tie(v_cnt, v_sum) = info[make_pair(v, x)];
    int par_cnt, par_sum; tie(par_cnt, par_sum) = info[make_pair(par, x)];
    int dist = tree_sum[u] + tree_sum[v] - 2 * tree_sum[par];
    int path_sum = u_sum + v_sum - 2 * par_sum;
    int path_cnt = u_cnt + v_cnt - 2 * par_cnt;

    cout << (dist - path_sum + y * path_cnt) << endl;
  }

  return 0;
}
