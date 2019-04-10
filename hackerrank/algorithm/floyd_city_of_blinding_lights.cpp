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

// graph by adjacency matrix

template <typename T>
struct Graph {
  int V;
  vector<vector<T>> adj;

  Graph(int V) : V(V) {
    adj.resize(V, vector<T>(V, INF));
    for (int i = 0; i < V; i++) adj[i][i] = 0;
  }

  void add_edge(int src, int dst, T weight) {
    adj[src][dst] = weight;
  }

};

template <typename T>
struct AllPairsShortestPath {
  Graph<T> g;
  vector<vector<T>> dist;

  AllPairsShortestPath(const Graph<T> &g) : g(g) {
    dist.resize(g.V, vector<T>(g.V));
    for (int i = 0; i < g.V; i++) {
      for (int j = 0; j < g.V; j++) dist[i][j] = g.adj[i][j];
    }
  }

  void warshall_floyd() {
    for (int k = 0; k < g.V; k++) {
      for (int i = 0; i < g.V; i++) {
        for (int j = 0; j < g.V; j++) {
          if (dist[i][k] != INF and dist[k][j] != INF) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }
  }

  bool has_negative_loop() {
    for (int i = 0; i < g.V; i++) {
      if (dist[i][i] < 0) return true;
    }
    return false;
  }
};


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int V, E; cin >> V >> E;
  Graph<int> g(V);
  REP(_, E) {
    int s, t, w; cin >> s >> t >> w; s--, t--;
    g.add_edge(s, t, w);
  }
  AllPairsShortestPath<int> apsp(g);
  apsp.warshall_floyd();
  int Q; cin >> Q;
  REP(_, Q) {
    int s, d; cin >> s >> d; s--, d--;
    cout << (apsp.dist[s][d] == INF ? -1 : apsp.dist[s][d]) << endl;
  }

  return 0;
}
