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

template <typename T>
struct Edge {
  int src, dst; T weight;

  Edge(int src, int dst, T weight) : src(src), dst(dst), weight(weight) { }

  bool operator < (const Edge<T> &e) const {
    return weight < e.weight;
  }
};

template <typename T>
struct Graph {
  int V;
  vector<Edge<T>> E;

  Graph(int V) : V(V) { }

  void add_edge(int src, int dst, T weight) {
    E.emplace_back(src, dst, weight);
  }
};

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

template <typename T>
struct MinimumSpanningTree {
  Graph<T> g;
  vector<Edge<T>> mst;
  T mincost;

  MinimumSpanningTree(const Graph<T> &g) : g(g) { }

  T run() {
    mincost = 0;
    sort(g.E.begin(), g.E.end());

    DisjointSet uf(g.V);

    for (int i = 0, edge_count = g.V - 1; edge_count; i++) {
      assert(i < (int)g.E.size());
      Edge<T> e = g.E[i];
      if (!uf.same(e.src, e.dst)) {
        uf.unite(e.src, e.dst);
        mst.emplace_back(e);
        mincost += e.weight;
        edge_count--;
      }
    }
    return mincost;
  }
};

ll max_cost[4010][4010];
vector<pair<int, ll>> edge[4010];

void dfs(int v, int p, int s, ll cost) {
  max_cost[s][v] = cost;
  for (auto e : edge[v]) {
    int n; ll c; tie(n, c) = e;
    if (n != p) dfs(n, v, s, max(cost, c));
  }
}


int main() {

  int N, M; scanf("%d %d", &N, &M);
  Graph<ll> g(N);
  REP(i, M) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c); a--, b--;
    g.add_edge(a, b, c);
    g.add_edge(b, a, c);
  }
  MinimumSpanningTree<ll> mst(g);
  mst.run();

  for (auto e : mst.mst) {
    edge[e.src].emplace_back(e.dst, e.weight);
    edge[e.dst].emplace_back(e.src, e.weight);
  }

  REP(i, N) dfs(i, -1, i, 0);

  int Q; scanf("%d", &Q);

  REP(i, Q) {
    int s, t; scanf("%d %d", &s, &t); s--, t--;
    printf("%lld\n", mst.mincost - max_cost[s][t]);
  }

  return 0;
}
