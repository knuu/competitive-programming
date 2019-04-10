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
struct Node {
  int v, src; T dist;
  Node(int v, int src, T dist) : v(v), src(src), dist(dist) { };
  bool operator < (const Node<T> &n) const {
    return dist > n.dist; // reverse
  }
};

template <typename T>
struct MinimumSpanningTree {
  Graph<T> g;
  vector<Node<T>> mst;
  int mincost;

  MinimumSpanningTree(const Graph<T> &g) : g(g) { }

  int prim(int s) {
    mincost = 0;

    vector<bool> used(g.V, false);

    priority_queue<Node<T>> que;
    que.emplace(s, -1, 0);

    while (!que.empty()) {
      Node<T> n = que.top(); que.pop();
      int v = n.v; T cost = n.dist;
      if (used[v]) continue;
      if (n.src != -1) mst.push_back(n);
      used[v] = true;
      mincost += cost;
      for (Edge<T> e : g.E[v]) {
        if (!used[e.dst]) que.emplace(e.dst, v, e.weight);
      }
    }
    return mincost;
  }
};


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int V, E; cin >> V >> E;
  Graph<int> g(V);
  REP(_, E) {
    int x, y, w; cin >> x >> y >> w; x--, y--;
    g.add_edge(x, y, w);
    g.add_edge(y, x, w);
  }
  MinimumSpanningTree<int> mst(g);
  int s; cin >> s; s--;
  cout << mst.prim(s) << endl;

  return 0;
}
