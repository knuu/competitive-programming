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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

vector<int> edge[2010];

int dfs(int v, int p, int dep, int dia) {
  int ret = dep > dia ? 1 : 0;
  for (int c : edge[v]) if (c != p) ret += dfs(c, v, dep+1, dia);
  return ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, K; cin >> N >> K;
  REP(i, N-1) {
    int a, b; cin >> a >> b; a--, b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  int ret = N;
  if (K % 2 == 0) {
    REP(i, N) ret = min(ret, dfs(i, -1, 0, K/2));
  } else {
    REP(i, N) {
      for (int c : edge[i]) ret = min(ret, dfs(i, c, 0, K/2) + dfs(c, i, 0, K/2));
    }
  }
  cout << ret << endl;
  return 0;
}
