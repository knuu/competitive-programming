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
    G[from].push_back(Edge(to, (int)G[to].size(), cap));
    G[to].push_back(Edge(from, (int)G[from].size()-1, 0));
  }

  void bfs(int source) {
    level.assign(V, -1);
    queue<int> que;
    que.push(source);
    level[source] = 0;
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (int i = 0; i < (int)G[v].size(); i++) {
	Edge &e = G[v][i];
	if (e.cap > 0 && level[e.to] < 0) {
	  level[e.to] = level[v] + 1;
	  que.push(e.to);
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
      while ((f = dfs(source, sink, INF)) > 0) {
	flow += f;
      }
    }
  }
};

int main() {

  int N;
  while (scanf("%d", &N) != EOF) {
    int M, L; scanf("%d %d", &M, &L);
    vector<vector<int>> Adj(N, vector<int>(N, INF));
    REP(i, N) Adj[i][i] = 0;
    REP(i, M) {
      int A, B, D; scanf("%d %d %d", &A, &B, &D); A--, B--;
      Adj[A][B] = Adj[B][A] = D;
    }
    REP(k, N) REP(i, N) REP(j, N) Adj[i][j] = min(Adj[i][j], Adj[i][k] + Adj[k][j]);
    MaxFlow<int> mf(2*N+2);
    REP(i, N) {
      int P; scanf("%d", &P);
      mf.add_edge(2*N, i, P);
    }
    REP(i, N) {
      int K; scanf("%d", &K);
      mf.add_edge(i+N, 2*N+1, K);
    }
    REP(i, N) REP(j, N) {
      if (Adj[i][j] < L) {
	mf.add_edge(i, j+N, INF);
      }
    }
    printf("%d\n", mf.dinic(2*N, 2*N+1));
  }
  return 0;
}
