#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

#define INF 1<<30
#define MAX_V 1024

// graph by adjacency list
struct Edge {
  int dst, weight;
  Edge(int dst, int weight) :
    dst(dst), weight(weight) { }
  bool operator < (const Edge &e) const {
    return weight > e.weight;
  }
};

struct Graph {
  int V;
  std::vector<Edge> E[MAX_V];

  Graph(int V) : V(V) { }

  void add_edge(int src, int dst, int weight) {
    E[src].push_back(Edge(dst, weight));
  }
};

// find shortest path by Bellman-Ford Algorithm
struct ShortestPath {
  const Graph g;
  int start;
  int dist[MAX_V], prev[MAX_V];
  bool negative_loop;

  ShortestPath(const Graph g, int start) :
    g(g), start(start) { }

  void bellman_ford() {
    negative_loop = false;
    std::fill(dist, dist + g.V, INF);
    dist[start] = 0;
    prev[start] = -1;
    for (int cnt = 0; cnt < g.V; cnt++) {
      bool update = false;
      for (int i = 0; i < g.V; i++) {
	for (Edge e : g.E[i]) {
	  if (dist[i] != INF && dist[i] + e.weight < dist[e.dst]) {
	    dist[e.dst] = dist[i] + e.weight;
	    prev[e.dst] = i;
	    if (cnt == g.V - 1) negative_loop = true;
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
      path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
  }

  bool has_negative_loop() {
    return negative_loop;
  }
};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int V, E, start;
  cin >> V >> E >> start;

  Graph g(V);
  REP(i, E) {
    int src, dst, weight;
    cin >> src >> dst >> weight;
    g.add_edge(src, dst, weight);
  }

  ShortestPath sp(g, start);
  sp.bellman_ford();
  if (sp.has_negative_loop()) {
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
