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

  T run(int source, int sink, T f) {
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

int N;

int row_idx(int r) { return r; }
int col_idx(int c) { return N + c; }

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  MinCostFlow<int> mcf(2 * N + 2);
  int source = 2 * N, sink = source + 1;

  vector<vector<int>> W(N, vector<int>(N)), E(N, vector<int>(N)), board(N, vector<int>(N));
  REP(i, N) REP(j, N) cin >> W[i][j];
  REP(i, N) REP(j, N) cin >> E[i][j];
  REP(i, N) {
    string row; cin >> row;
    REP(j, N) board[i][j] = row[j] == 'o';
  }

  ll ans = 0;
  REP(i, N) REP(j, N) if (board[i][j]) ans += E[i][j];

  REP(i, N) mcf.add_edge(source, row_idx(i), 1, 0);

  ll geta = 1000;
  REP(i, N) REP(j, N) {
    if (board[i][j]) {
      mcf.add_edge(row_idx(i), col_idx(j), 1, -E[i][j] + geta);
    } else {
      mcf.add_edge(row_idx(i), col_idx(j), 1, W[i][j] + geta);
    }
  }

  REP(i, N) mcf.add_edge(col_idx(i), sink, 1, 0);

  ll cost = mcf.run(source, sink, N) - N * geta;
  ans += cost;
  cout << ans << endl;

  vector<tuple<int, int, string>> proc;
  REP(i, N) REP(j, N) {
    if (board[i][j]) {
      if (mcf.G[row_idx(i)][j+1].cap == 1) proc.emplace_back(i+1, j+1, "erase");
    } else {
      if (mcf.G[row_idx(i)][j+1].cap == 0) proc.emplace_back(i+1, j+1, "write");
    }
  }

  cout << proc.size() << endl;
  for (auto t : proc) {
    int i, j; string p; tie(i, j, p) = t;
    cout << i << ' ' << j << ' ' << p << endl;
  }

  return 0;
}
