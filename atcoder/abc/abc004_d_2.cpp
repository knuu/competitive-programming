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

const int INF = 1e7;

template <typename T>
struct MinCostFlow {
  struct Edge {
    int to, rev; T cap, cost;
    Edge(int to, int rev, T cap, T cost) : to(to), rev(rev), cap(cap), cost(cost) { }
  };

  struct Node {
    int v; T dist;
    Node(int v, T dist) : v(v), dist(dist) { };
    bool operator < (const Node &n) const {
      return dist > n.dist; // reverse
    }
  };

  typedef vector<Edge> Edges;
  vector<Edges> G;
  int V;
  vector<int> dist, h, prevv, preve;

  MinCostFlow(int V) : V(V) { G.resize(V); }

  void add_edge(int from, int to, T cap, T cost) {
    G[from].emplace_back(to, G[to].size(), cap, cost);
    G[to].emplace_back(from, (int)G[from].size()-1, 0, -cost);
  }

  T primal_dual(int source, int sink, T f) {
    T res = 0;
    h.resize(V, 0);
    prevv.resize(V), preve.resize(V);
    while (f > 0) {
      priority_queue<Node> pque;
      dist.assign(V, INF);
      dist[source] = 0;
      pque.emplace(source, 0);
      while (not pque.empty()) {
        Node n = pque.top(); pque.pop();
        int v = n.v; T cost = n.dist;
        if (dist[v] < cost) continue;
        for (int i = 0; i < (int)G[v].size(); i++) {
          Edge e = G[v][i];
          if (e.cap > 0 and dist[v] - h[e.to] < dist[e.to] - e.cost - h[v]) {
            dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
            prevv[e.to] = v, preve[e.to] = i;
            pque.emplace(e.to, dist[e.to]);
          }
        }
      }
      if (dist[sink] == INF) return -1;
      for (int v = 0; v < V; v++) h[v] += dist[v];

      T d = f;
      for (int v = sink; v != source; v = prevv[v]) {
        d = min(d, G[prevv[v]][preve[v]].cap);
      }
      f -= d;
      res += d * h[sink];
      for (int v = sink; v != source; v = prevv[v]) {
        Edge &e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
    }
    return res;
  }
};


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int R, G, B; cin >> R >> G >> B;

  MinCostFlow<int> mcf(1001+3+2);
  int rs = 1001, gs = rs + 1, bs = gs + 1;
  int source = bs + 1, sink = source + 1;

  mcf.add_edge(source, rs, R, 0);
  mcf.add_edge(source, gs, G, 0);
  mcf.add_edge(source, bs, B, 0);

  REP(i, 1001) mcf.add_edge(rs, i, 1, abs(i-400));
  REP(i, 1001) mcf.add_edge(gs, i, 1, abs(i-500));
  REP(i, 1001) mcf.add_edge(bs, i, 1, abs(i-600));

  REP(i, 1001) mcf.add_edge(i, sink, 1, 0);

  cout << mcf.primal_dual(source, sink, R + G + B) << endl;

  return 0;
}
