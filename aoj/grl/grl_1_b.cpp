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

#define INF 1<<30

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
struct ShortestPath {
  const Graph<T> g;
  vector<T> dist;
  vector<int> prev;

  ShortestPath(const Graph<T> g) : g(g) { dist.resize(g.V), prev.resize(g.V); }

  void bellman_ford(int start) {
    dist.assign(g.V, INF);
    dist[start] = 0;
    prev[start] = -1;
    while (true) {
      bool update = false;
      for (int i = 0; i < g.V; i++) {
        for (Edge<T> e : g.E[i]) {
          if (dist[i] != INF && dist[i] + e.weight < dist[e.dst]) {
            dist[e.dst] = dist[i] + e.weight;
            prev[e.dst] = i;
            update = true;
          }
        }
      }
      if (!update) break;
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

  bool find_negative_loop(int start) {
    dist.assign(g.V, INF);
    dist[start] = 0;
    for (int i = 0; i < g.V; i++) {
      for (int j = 0; j < g.V; j++) {
        for (Edge<T> e : g.E[j]) {
          if (dist[j] != INF && dist[j] + e.weight < dist[e.dst]) {
            dist[e.dst] = dist[j] + e.weight;
            if (i == g.V - 1) return true;
          }
        }
      }
    }
    return false;
  }
};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int V, E, r; cin >> V >> E >> r;
  Graph<int> g(V);
  REP(_, E) {
    int s, t, d; cin >> s >> t >> d;
    g.add_edge(s, t, d);
  }
  ShortestPath<int> sp(g);
  if (sp.find_negative_loop(r)) {
    cout << "NEGATIVE CYCLE" << endl;
  } else {
    REP(i, g.V) {
      if (sp.dist[i] == INF) {
        cout << "INF" << endl;
      } else {
        cout << sp.dist[i] << endl;
      }
    }
  }
  return 0;
}
