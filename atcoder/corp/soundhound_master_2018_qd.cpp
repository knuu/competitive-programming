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

  void run(int start) {
    priority_queue<Node<T>> que;
    dist.assign(g.V, std::numeric_limits<T>::max());
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

  int N, M, s, t; cin >> N >> M >> s >> t; s--, t--;
  Graph<ll> yen(N), snu(N);
  REP(i, M) {
    int u, v, a, b; cin >> u >> v >> a >> b; u--, v--;
    yen.add_edge(u, v, a);
    yen.add_edge(v, u, a);
    snu.add_edge(u, v, b);
    snu.add_edge(v, u, b);
  }

  ShortestPath<ll> yen_sp(yen), snu_sp(snu);
  yen_sp.run(s);
  snu_sp.run(t);

  ll min_cost = 1e15;
  vector<ll> ans(N);
  REP(i, N) {
    min_cost = min(min_cost, yen_sp.dist[N-i-1] + snu_sp.dist[N-i-1]);
    ans[N-i-1] = static_cast<ll>(1e15) - min_cost;
  }
  for (ll a : ans) cout << a << endl;
  return 0;
}
