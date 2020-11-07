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

vector<vector<int>> edge;

void dfs(int v, int p, int d, vector<int>& dist) {
  dist[v] = d;
  for (int c : edge[v]) {
    if (p == c) continue;
    dfs(c, v, d + 1, dist);
  }
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  int u, v; cin >> u >> v; u--, v--;
  edge.resize(N);
  REP(i, N-1) {
    int a, b; cin >> a >> b; a--, b--;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  vector<int> taka(N), aoki(N);
  dfs(u, -1, 0, taka);
  dfs(v, -1, 0, aoki);
  int ans = 0;
  REP(i, N) {
    if (taka[i] < aoki[i]) {
      ans = max(ans, aoki[i] - 1);
    }
  }
  cout << ans << endl;
  return 0;
}
