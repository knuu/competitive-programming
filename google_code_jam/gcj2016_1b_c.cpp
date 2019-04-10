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
struct BipartiteMatching {
  struct Edge {
    int to, rev; T cap;
    Edge(int to, int rev, T cap) : to(to), rev(rev), cap(cap) { }
  };

  typedef vector<Edge> Edges;
  vector<Edges> G;
  int V, source, sink;
  vector<int> level, iter;

  BipartiteMatching(int V1, int V2) {
    V = V1 + V2 + 2, source = V-2, sink = V-1;
    G.resize(V);
    add_sink_source(V1, V2);
  }

  void add_edge(int from, int to) {
    G[from].emplace_back(to, G[to].size(), 1);
    G[to].emplace_back(from, (int)G[from].size()-1, 0);
  }

  void add_sink_source(int V1, int V2) {
    for (int i = 0; i < V1; i++) add_edge(source, i);
    for (int i = V1; i < V1+V2; i++) add_edge(i, sink);
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

  T dinic() {
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

  int T; cin >> T;
  REP(t, T) {
    int N; cin >> N;
    vector<pair<string, string>> topics(N);
    set<string> F, S;
    REP(i, N) {
      string f, s; cin >> f >> s;
      F.insert(f), S.insert(s);
      topics[i] = make_pair(f, s);
    }
    vector<string> vf, vs;
    for (string f : F) vf.push_back(f);
    for (string s : S) vs.push_back(s);

    map<string, int> mapf, maps;
    REP(i, vf.size()) mapf[vf[i]] = i;
    REP(i, vs.size()) maps[vs[i]] = i + (int)vf.size();

    BipartiteMatching<int> bp(F.size(), S.size());
    for (auto p : topics) bp.add_edge(mapf[p.first], maps[p.second]);
    cout << "Case #" << t+1 << ": " << (N + bp.dinic() - ((int)bp.G.size() - 2)) << endl;
  }

  return 0;
}
