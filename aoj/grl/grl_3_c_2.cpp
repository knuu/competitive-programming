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
  vector<int> vs, cmp, stk;
  vector<bool> used, added;

  StronglyConnectedComponents(int V) : V(V) {
    used.assign(V, false), added.assign(V, false);
    G.resize(V), rG.resize(V);
    stk.resize(4*V), cmp.resize(V);
  }

  void add_edge(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
  }

  void dfs(int s) {
    int sp = 0;
    stk[sp++] = s;
    while (sp) {
      int v = stk[sp-1];
      used[v] = true;
      bool pushed = false;
      for (int c : G[v]) if (not used[c]) stk[sp++] = c, pushed = true;
      if (not pushed) {
        if (not added[v]) added[v] = true, vs.push_back(v);
        sp--;
      }
    }
  }

  void rdfs(int s, int k) {
    int sp = 0;
    stk[sp++] = s;
    while (sp) {
      int v = stk[sp-1]; sp--;
      used[v] = true;
      cmp[v] = k;
      for (int c : rG[v]) if (not used[c]) stk[sp++] = c;
    }
  }

  int run() {
    fill(used.begin(), used.end(), false);
    fill(added.begin(), added.end(), false);
    vs.clear();
    for (int v = 0; v < V; v++) if (!used[v]) dfs(v);
    fill(used.begin(), used.end(), false);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--) if (not used[vs[i]]) rdfs(vs[i], k++);
    return k;
  }
};

int main() {
  int V, E; scanf("%d %d", &V, &E);
  StronglyConnectedComponents scc(V);
  REP(_, E) {
    int f, t; scanf("%d %d", &f, &t);
    scc.add_edge(f, t);
  }
  scc.run();
  int Q; scanf("%d", &Q);
  REP(_, Q) {
    int x, y; scanf("%d %d", &x, &y);
    printf("%d\n", (scc.cmp[x] == scc.cmp[y]));
  }
  return 0;
}
