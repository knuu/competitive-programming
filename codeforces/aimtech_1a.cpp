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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, M; cin >> N >> M;
  vector<vector<int>> adj(N, vector<int>(N, 0));
  REP(i, M) {
    int u, v; cin >> u >> v; u--, v--;
    adj[u][v] = adj[v][u] = 1;
  }
  string ans(N, '0');
  REP(i, N) {
    bool flag = true;
    REP(j, N) {
      if (i != j and adj[i][j] == 0) flag = false;
    }
    if (flag) ans[i] = 'b';
  }
  int s = 0;
  while (s < N and ans[s] == 'b') s++;
  if (s < N) {
    ans[s] = 'a';
    REP(i, N) {
      if (i != s and ans[i] == '0') {
        ans[i] = adj[s][i] ? 'a' : 'c';
      }
    }
  }
  REP(i, N) FOR(j, i+1, N) {
    if ((abs(ans[i] - ans[j]) == 2 and adj[i][j] == 1) or (abs(ans[i] - ans[j]) <= 1 and adj[i][j] == 0)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  cout << ans << endl;
  return 0;
}
