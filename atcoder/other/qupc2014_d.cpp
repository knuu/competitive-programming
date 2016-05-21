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

#define INF (int)1e9

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

#define INF (int)1e9

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
  // Use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, M, K, S, G; cin >> N >> M >> K >> S >> G;
  //cout << N << ' ' << M << ' ' << K << ' ' << S << ' ' << G << endl;
  vector<ll> x(K+1), f(K+1);
  Graph<ll> g(N);
  REP(_, M) {
    int a, b, d; cin >> a >> b >> d;
    //cout << a << ' ' << b << ' ' << d << endl;
    g.add_edge(a, b, d);
    g.add_edge(b, a, d);
  }
  REP(i, K) cin >> x[i+1] >> f[i+1];
  ShortestPath<ll> sp1(g), sp2(g);
  sp1.dijkstra(S), sp2.dijkstra(G);
  ll max_c = INT_MAX;
  REP(i, N) {
    ll cost = 0;
    for (int j = 0; j < K; j++) {
      if (x[j] <= sp1.dist[i] and sp1.dist[i] < x[j+1]) {
        cost += f[j];
      }
      if (x[j] <= sp2.dist[i] and sp2.dist[i] < x[j+1]) {
        cost += f[j];
      }
    }
    if (x[K] <= sp1.dist[i]) cost += f[K];
    if (x[K] <= sp2.dist[i]) cost += f[K];
    max_c = min(max_c, cost);
  }
  cout << max_c << endl;
  return 0;
}
