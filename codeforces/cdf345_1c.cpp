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

struct StronglyConnectedComponents {
  int V;
  vector<vector<int>> G, rG;
  vector<int> vs, cmp;
  vector<bool> used;

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
    for (int c : G[v]) if (not used[c]) dfs(c);
    vs.push_back(v);
  }

  void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for (int c : rG[v]) if (not used[c]) rdfs(c, k);
  }

  int run() {
    fill(used.begin(), used.end(), false);
    vs.clear();
    for (int v = 0; v < V; v++) if (!used[v]) dfs(v);
    fill(used.begin(), used.end(), false);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--) if (!used[vs[i]]) rdfs(vs[i], k++);
    return k;
  }
};

int main() {
  int N, M; scanf("%d %d", &N, &M);
  vector<vector<int>> mat(N, vector<int>(M, 0));
  REP(i, N) REP(j, M) scanf("%d", &mat[i][j]);

  StronglyConnectedComponents scc(N*M);
  REP(i, N) {
    vector<P> row;
    REP(j, M) row.push_back(P(mat[i][j], i * M + j));
    sort(ALL(row));
    REP(j, M-1) {
      if (row[j].first == row[j+1].first) scc.add_edge(row[j+1].second, row[j].second);
      scc.add_edge(row[j].second, row[j+1].second);
    }
  }

  REP(i, M) {
    vector<P> col;
    REP(j, N) col.push_back(P(mat[j][i], j * M + i));
    sort(ALL(col));
    REP(j, N-1) {
      if (col[j].first == col[j+1].first) scc.add_edge(col[j+1].second, col[j].second);
      scc.add_edge(col[j].second, col[j+1].second);
    }
  }

  int k = scc.run();
  vector<int> dp(k, 1);
  vector<vector<int>> group(k);
  REP(i, N*M) group[scc.cmp[i]].push_back(i);

  // DAG上をDP
  REP(i, k) {
    for (int v : group[i]) {
      for (int par : scc.rG[v]) {
        if (scc.cmp[par] < scc.cmp[v]) dp[i] = max(dp[i], dp[scc.cmp[par]] + 1);
      }
    }
  }

  REP(i, N) {
    REP(j, M) {
      if (j) printf(" ");
      printf("%d", dp[scc.cmp[i*M+j]]);
    }
    printf("\n");
  }

  return 0;
}
