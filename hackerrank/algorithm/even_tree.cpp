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

int V, E;

int count_even_tree(vector<vector<int>> &edge);
int count_nodes(int v, int par, vector<vector<int>> &origin, vector<vector<int>> &next_edge);
void divide(int v, int par, vector<vector<int>> &edge);

int count_even_tree(vector<vector<int>> &edge) {
  REP(i, V) {
    if (edge[i].size()) {
      for (int c : edge[i]) {
        vector<vector<int>> e1(V), e2(V);
        if (i < c and count_nodes(i, c, edge, e1) % 2 == 0) {
          assert(count_nodes(c, i, edge, e2) % 2 == 0);
          return 1 + count_even_tree(e1) + count_even_tree(e2);
        }
      }
    }
  }
  return 0;
}

int count_nodes(int v, int par, vector<vector<int>> &origin, vector<vector<int>> &next_edge) {
  int ret = 1;
  for (int c : origin[v]) {
    if (c != par) {
      next_edge[v].push_back(c);
      next_edge[c].push_back(v);
      ret += count_nodes(c, v, origin, next_edge);
    }
  }
  return ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> V >> E;
  vector<vector<int>> edge(V);
  REP(i, E) {
    int s, t; cin >> s >> t; s--, t--;
    edge[s].push_back(t);
    edge[t].push_back(s);
  }
  cout << count_even_tree(edge) << endl;
  return 0;
}
