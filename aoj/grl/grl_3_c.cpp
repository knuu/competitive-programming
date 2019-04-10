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

#define MAX_V 100000

int V;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];

void add_edge(int from, int to) {
  G[from].push_back(to);
  rG[to].push_back(from);
}

void dfs(int v) {
  used[v] = true;
  for (int i = 0; i < (int)G[v].size(); i++) {
    if (!used[G[v][i]]) dfs(G[v][i]);
  }
  vs.push_back(v);
}

void rdfs(int v, int k) {
  used[v] = true;
  cmp[v] = k;
  for (int i = 0; i < (int)rG[v].size(); i++) {
    if (!used[rG[v][i]]) rdfs(rG[v][i], k);
  }
}

int scc() {
  memset(used, 0, sizeof(used));
  vs.clear();
  for (int v = 0; v < V; v++) {
    if (!used[v]) dfs(v);
  }
  memset(used, 0, sizeof(used));
  int k = 0;
  for (int i = vs.size() - 1; i >= 0; i--) {
    if (!used[vs[i]]) rdfs(vs[i], k++);
  }
  return k;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int E; cin >> V >> E;
  REP(_, E) {
    int f, t; cin >> f >> t;
    add_edge(f, t);
  }
  scc();
  int Q; cin >> Q;
  REP(_, Q) {
    int x, y; cin >> x >> y;
    cout << (cmp[x] == cmp[y]) << endl;
  }
  return 0;
}
