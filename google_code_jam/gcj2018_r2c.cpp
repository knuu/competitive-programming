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

int ans;
int M;
vector<pair<int, int>> formula;

void dfs(vector<int> G) {
  ans = max(ans, G[0]);
  //for (int i = 0; i < M; i++) cout << G[i] << (i == M - 1 ? '\n' : ' ');
  REP(i, M) {
    pair<int, int> f = formula[i];
    int x, y; tie(x, y) = f;
    if (x != 0 and y != 0 and G[x] > 0 and G[y] > 0) {
      G[x]--, G[y]--, G[i]++;
      dfs(G);
      G[x]++, G[y]++, G[i]--;
    }
  }
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  REP(testcase, T) {
    cin >> M;
    formula.resize(M);
    //cout << M << endl;
    REP(i, M) {
      int x, y; cin >> x >> y; x--, y--;
      formula[i] = make_pair(x, y);
    }
    vector<int> G(M);
    REP(i, M) cin >> G[i];
    //REP(i, M) cout << G[i] << (i == M - 1 ? '\n' : ' ');
    ans = G[0];
    dfs(G);
    cout << "Case #" << testcase + 1 << ": " << ans << endl;
  }

  return 0;
}
