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

#define INF 1<<29

template <typename T>
struct MaxFlow {
  struct Edge {
    int to, rev; T cap;
    Edge(int to, int rev, T cap) : to(to), rev(rev), cap(cap) { }
  };

  typedef vector<Edge> Edges;
  vector<Edges> G;
  int V;
  vector<int> level, iter;

  MaxFlow(int V) : V(V) { G.resize(V); }

  void add_edge(int from, int to, T cap) {
    G[from].emplace_back(to, G[to].size(), cap);
    G[to].emplace_back(from, (int)G[from].size()-1, 0);
  }

  void bfs(int source) {
    level.assign(V, -1);
    queue<int> que;
    que.emplace(source);
    level[source] = 0;
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (int i = 0; i < (int)G[v].size(); i++) {
	Edge &e = G[v][i];
	if (e.cap > 0 && level[e.to] < 0) {
	  level[e.to] = level[v] + 1;
	  que.emplace(e.to);
	}
      }
    }
  }

  T dfs(int v, int sink, T flow) {
    if (v == sink) return flow;
    for (int &i = iter[v]; i < (int)G[v].size(); i++) {
      Edge &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
	T d = dfs(e.to, sink, min(e.cap, flow));
	if (d > 0) {
	  e.cap -= d;
	  G[e.to][e.rev].cap += d;
	  return d;
	}
      }
    }
    return 0;
  }

  T dinic(int source, int sink) {
    T flow = 0;
    while (true) {
      bfs(source);
      if (level[sink] < 0) return flow;
      iter.assign(V, 0);
      T f;
      while ((f = dfs(source, sink, INF)) > 0) flow += f;
    }
  }
};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int V, E; cin >> V >> E;
  MaxFlow<int> mf(V);
  REP(i, E) {
    int u, v, c; cin >> u >> v >> c;
    mf.add_edge(u, v, c);
  }
  cout << mf.dinic(0, V-1) << endl;
  return 0;
}
