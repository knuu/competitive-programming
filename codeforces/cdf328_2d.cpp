#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> P;
typedef vector<int> Vi;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int N, M;
bool subtree[130000];
Vi G[130000];
int attack[130000];

int depth[130000];

bool dfs1(int v, int p) {
  bool ret = subtree[v];
  for (int c : G[v]) {
    if (c != p) {
      ret |= dfs1(c, v);
    }
  }
  return subtree[v] = ret;
}

void dfs2(int v, int p, int d) {
  depth[v] = d;
  for (int c : G[v]) {
    if (c != p && subtree[c]) {
      dfs2(c, v, d+1);
    }
  }
}

P diameter() {
  int s = attack[0];
  fill(depth, depth + N, -1);
  dfs2(s, -1, 0);
  int v = 0, v_d = -1;
  REP(i, N) {
    if (v_d < depth[i]) {
      v = i;
      v_d = depth[i];
    }
  }
  fill(depth, depth + N, -1);
  dfs2(v, -1, 0);
  int w = 0, w_d = -1;
  REP(i, N) {
    if (w_d < depth[i]) {
      w = i;
      w_d = depth[i];
    }
  }
  return P(min(v, w), w_d);
}		      

int main() {
  scanf("%d %d", &N, &M);
  REP(i, N-1) {
    int u, v;
    scanf("%d %d", &u, &v); u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  fill(subtree, subtree + N, false);
  REP(i, M) {
    int v;
    scanf("%d", &v); v--;
    attack[i] = v;
    subtree[v] = true;
  }
  dfs1(attack[0], -1);
  
  int edge_cnt = 0;
  REP(i, N) {
    if (subtree[i]) {
      for (int v : G[i]) {
	if (subtree[v]) edge_cnt++;
      }
    }
  }
  
  P d = diameter();
  cout << d.first + 1 << endl;
  cout << edge_cnt - d.second << endl;
  return 0;
}
