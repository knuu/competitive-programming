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
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

struct StronglyConnectedComponents {
  int V;
  std::vector<std::vector<int>> G, rG;
  std::vector<int> vs, cmp;
  std::vector<bool> used;

  StronglyConnectedComponents(int V) : V(V) {
    used.assign(V, false);
    G.resize(V), rG.resize(V);
    cmp.resize(V);
  }

  void add_edge(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
  }

  void dfs(int v) {
    used[v] = true;
    for (int c : G[v])
      if (not used[c]) dfs(c);
    vs.push_back(v);
  }

  void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for (int c : rG[v])
      if (not used[c]) rdfs(c, k);
  }

  int run() {
    fill(used.begin(), used.end(), false);
    vs.clear();
    for (int v = 0; v < V; v++)
      if (!used[v]) dfs(v);
    fill(used.begin(), used.end(), false);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--)
      if (!used[vs[i]]) rdfs(vs[i], k++);
    return k;
  }
};


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int V, E; cin >> V >> E;
  StronglyConnectedComponents scc(V);
  REP(i, E) {
    int s, t; cin >> s >> t;
    scc.add_edge(s, t);
  }
  scc.run();
  int Q; cin >> Q;
  REP(i, Q) {
    int u, v; cin >> u >> v;
    cout << (scc.cmp[u] == scc.cmp[v] ? 1 : 0) << endl;
  }

  return 0;
}
