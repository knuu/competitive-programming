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

// graph by adjacency list
template <typename T>
struct Edge {
  int dst, c; T weight;
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

#define INF INT_MAX

template <typename T>
struct Node {
  int v; T dist; int pre;
  Node(int v, T dist, int pre) : v(v), dist(dist), pre(pre) { };
  bool operator < (const Node<T> &n) const {
    return dist > n.dist; // reverse
  }
};

template <typename T>
struct ShortestPath {
  const Graph<T> g;
  vector<map<int, T>> dist;
  vector<int> prev;

  ShortestPath(const Graph<T> g) : g(g) { dist.resize(g.V), prev.resize(g.V); }

  void dijkstra(int start) {
    deque<Node<T>> que;
    dist[start][-1] = 0;
    que.emplace_back(start, 0, -1);

    while (!que.empty()) {
      Node<T> n = que.front(); que.pop_front();
      int v = n.v; T cost = n.dist, pre = n.pre;
      //cout << v << ' ' << cost << ' ' << pre << endl;
      if (v == g.V - 1) {
        cout << cost << endl;
        return ;
      }
      if (dist[v].find(pre) != dist[v].end() and dist[v][pre] < cost) continue;
      for (Edge<T> e : g.E[v]) {
        if (dist[e.dst].find(e.weight) == dist[e.dst].end() or dist[v][pre] < dist[e.dst][e.weight] - (pre != e.weight)) {
          dist[e.dst][e.weight] = dist[v][pre] + (pre != e.weight);
          if (pre == e.weight) {
            que.emplace_front(e.dst, dist[e.dst][e.weight], e.weight);
          } else {
            que.emplace_back(e.dst, dist[e.dst][e.weight], e.weight);
          }
        }
      }
    }
    cout << -1 << endl;
  }

  vector<int> build_path(int goal) {
    vector<int> path;
    for (int v = goal; v != -1; v = prev[v]) {
      path.emplace_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
  }
};

int used[100010];

template <typename T>
void dfs(const Graph<T> &g, int v) {
  used[v] = 1;
  for (auto e : g.E[v]) {
    if (not used[e.dst]) dfs(g, e.dst);
  }
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  Graph<int> g(N);

  REP(_, M) {
    int p, q, c; cin >> p >> q >> c; p--, q--, c--;
    g.add_edge(p, q, c);
    g.add_edge(q, p, c);
  }

  dfs(g, 0);
  if (not used[g.V-1]) {
    cout << -1 << endl;
    return 0;
  }

  /*
  REP(i, g.V) {
    cout << i << "----" << endl;
    for (auto e : g.E[i]) {
      cout << e.dst << ' ' << e.weight << endl;
    }
  }
  //*/

  ShortestPath<int> sp(g);
  sp.dijkstra(0);
  return 0;
}
