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

int N;
vector<vector<pair<int, int>>> edges;
vector<int> colors;

void dfs(int v, int par, int par_color) {
  int color = 1;
  for (auto e : edges[v]) {
    int c, i; tie(c, i) = e;
    if (c == par) continue;
    if (color == par_color) color++;
    colors[i] = color;
    dfs(c, v, color);
    color++;
  }
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  edges.resize(N);
  REP(i, N-1) {
    int a, b; cin >> a >> b; a--, b--;
    edges[a].emplace_back(b, i);
    edges[b].emplace_back(a, i);
  }

  int ans = 0;
  REP(i, N) ans = max(ans, (int)edges[i].size());
  colors.resize(N-1, -1);
  dfs(0, -1, -1);

  cout << ans << endl;
  for (int c : colors) {
    cout << c << endl;
  }


  return 0;
}
