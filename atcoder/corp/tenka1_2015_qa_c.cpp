#include <bits/stdc++.h>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

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

  int M, N; cin >> M >> N;
  vector<vector<int>> A(M, vector<int>(N)), B = A;
  REP(i, M) REP(j, N) cin >> A[i][j];
  REP(i, M) REP(j, N) cin >> B[i][j];

  int cnt = 0;
  vector<vector<pair<int, int>>> diff(2);

  REP(i, M) REP(j, N) {
    if (A[i][j] != B[i][j]) {
      cnt++;
      diff[A[i][j]].emplace_back(i, j);
    }
  }

  int S = diff[0].size(), T = diff[1].size(), V = S + T, source = V, sink = source + 1;
  MaxFlow<int> mf(V + 2);
  REP(i, S) mf.add_edge(source, i, 1);
  REP(j, T) mf.add_edge(S+j, sink, 1);
  REP(i, S) REP(j, T) {
    int r1, c1; tie(r1, c1) = diff[0][i];
    int r2, c2; tie(r2, c2) = diff[1][j];
    if (abs(r1-r2) + abs(c1-c2) == 1) {
      mf.add_edge(i, S+j, 1);
    }
  }

  cout << cnt - mf.dinic(source, sink) << endl;
  return 0;
}
