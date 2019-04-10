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

vector<int> edge[100000];
int dp[100000][11];

void dfs(int v, int d, int c) {
  if (d < 0 or dp[v][d]) return ;
  dp[v][d] = c;
  dfs(v, d - 1, c);
  for (int ch : edge[v]) {
    dfs(ch, d - 1, c);
  }
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  REP(i, M) {
    int a, b; cin >> a >> b; a--, b--;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  int Q; cin >> Q;
  vector<tuple<int, int, int>> query;
  REP(i, Q) {
    int v, d, c; cin >> v >> d >> c; v--;
    query.emplace_back(v, d, c);
  }

  REP(i, Q) {
    int v, d, c; tie(v, d, c) = query[Q-i-1];
    dfs(v, d, c);
  }

  REP(i, N) cout << dp[i][0] << endl;

  return 0;
}
