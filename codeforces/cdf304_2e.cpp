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

#define INF (1<<29)

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
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  MaxFlow<int> mf(2 * N + 2);
  int A[101], B[101];
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];
  REP(i, N) {
    mf.add_edge(2 * N, i, A[i]);
    mf.add_edge(i + N, 2 * N + 1, B[i]);
    mf.add_edge(i, i + N, INF);
  }
  int a_sum = accumulate(A, A+N, 0), b_sum = accumulate(B, B+N, 0);
  if (a_sum != b_sum) {
    cout << "NO" << endl;
    return 0;
  }
  REP(i, M) {
    int p, q;
    cin >> p >> q; p--, q--;
    mf.add_edge(p, q + N, INF);
    mf.add_edge(q, p + N, INF);
  }

  if (a_sum != mf.dinic(2 * N, 2 * N + 1)) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    int A[101][101];
    REP(i, N) REP(j, N) A[i][j] = 0;
    REP(i, N) {
      for (auto e : mf.G[i]) {
	if (N <= e.to && e.to < 2 * N) {
	  A[i][e.to - N] = INF - e.cap;
	}
      }
    }
    REP(i, N) {
      REP(j, N) cout << A[i][j] << (j == N-1 ? '\n' : ' ');
    }
  }    
  return 0;
}
