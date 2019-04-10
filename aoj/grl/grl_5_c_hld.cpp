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

// graph by adjacency list
template <typename T>
struct Edge {
  int dst; T weight;
  Edge(int dst, T weight) : dst(dst), weight(weight) { }
  bool operator < (const Edge<T> &e) const {
    return weight > e.weight;
  }
};

template <typename T>
struct Graph {
  int V;
  vector<vector<Edge<T>>> E;
  Graph(int V) : V(V) { E.resize(V); }
  void add_edge(int src, int dst, T weight) {
    E[src].emplace_back(dst, weight);
  }
};

template <typename T>
struct HeavyLightDecomposition {
  const Graph<T> g;
  vector<int> vid, head, heavy, parent;
  HeavyLightDecomposition(const Graph<T> g, int root = 0) : g(g), vid(g.V, -1), head(g.V), heavy(g.V, -1), parent(g.V) {
    dfs(root, -1);
    bfs(root);
  }

  int dfs(int v, int par) {
    parent[v] = par;
    int sub = 1, max_sub = 0;
    for (Edge<T> child : g.E[v]) {
      if (child.dst != par) {
        int child_sub = dfs(child.dst, v);
        sub += child_sub;
        if (child_sub > max_sub) {
          max_sub = child_sub;
          heavy[v] = child.dst;
        }
      }
    }
    return sub;
  }

  void bfs(int root = 0) {
    int k = 0;
    queue<int> que({root});
    while (not que.empty()) {
      int r = que.front(); que.pop();
      for (int v = r; v != -1; v = heavy[v]) {
        vid[v] = k++;
        head[v] = r;
        for (Edge<T> child : g.E[v]) {
          if (child.dst != parent[v] and child.dst != heavy[v]) que.push(child.dst);
        }
      }
    }
  }

  int lca(int u, int v) {
    while(head[u] != head[v]) {
      if (vid[u] > vid[v]) swap(u, v);
      v = parent[head[v]];
    }
    if (vid[u] > vid[v]) swap(u, v);
    return u;
  }
};

int main() {
  int N; scanf("%d", &N);
  Graph<int> g(N);
  REP(i, N) {
    int k; scanf("%d", &k);
    REP(_, k) {
      int c; scanf("%d", &c);
      g.add_edge(i, c, 1);
      g.add_edge(c, i, 1);
    }
  }

  HeavyLightDecomposition<int> hld(g);
  REP(i, N) cout << hld.vid[i] << (i == N-1 ? '\n' : ' ');
  REP(i, N) cout << hld.head[i] << (i == N-1 ? '\n' : ' ');
  REP(i, N) cout << hld.heavy[i] << (i == N-1 ? '\n' : ' ');
  REP(i, N) cout << hld.parent[i] << (i == N-1 ? '\n' : ' ');


  int Q; scanf("%d", &Q);
  REP(_, Q) {
    int u, v; scanf("%d %d", &u, &v);
    printf("%d\n", hld.lca(u, v));
  }
  return 0;
}
