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

#define INF INT_MAX

template <typename T>
struct Node {
  int v; T dist;
  Node(int v, T dist) : v(v), dist(dist) { };
  bool operator < (const Node<T> &n) const {
    return dist > n.dist; // reverse
  }
};

template <typename T>
struct ShortestPath {
  const Graph<T> g;
  vector<T> dist;
  vector<int> prev;

  ShortestPath(const Graph<T> g) : g(g) { dist.resize(g.V), prev.resize(g.V); }

  void dijkstra(int start) {
    priority_queue<Node<T>> que;
    dist.assign(g.V, INF);
    dist[start] = 0;
    que.emplace(start, 0);
    prev[0] = -1;

    while (!que.empty()) {
      Node<T> n = que.top(); que.pop();
      int v = n.v; T cost = n.dist;
      if (dist[v] < cost) continue;
      for (Edge<T> e : g.E[v]) {
        if (dist[v] < dist[e.dst] - e.weight) {
          dist[e.dst] = dist[v] + e.weight;
          prev[e.dst] = v;
          que.emplace(e.dst, dist[e.dst]);
        }
      }
    }
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


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  REP(_, T) {
    int V, E; cin >> V >> E;
    Graph<int> g(V);
    REP(_, E) {
      int s, t, r; cin >> s >> t >> r; s--, t--;
      g.add_edge(s, t, r);
      g.add_edge(t, s, r);
    }
    ShortestPath<int> sp(g);
    int s; cin >> s; s--;
    sp.dijkstra(s);
    if (s != V-1) {
      REP(i, V) if (i != s) cout << (sp.dist[i] == INF ? -1 : sp.dist[i]) << (i == V-1 ? '\n' : ' ');
    } else {
      REP(i, V-1) cout << (sp.dist[i] == INF ? -1 : sp.dist[i]) << (i == V-2 ? '\n' : ' ');
    }
  }

  return 0;
}
