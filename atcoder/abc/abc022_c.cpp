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

const int INF = (int)1e9;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M;
  int A[310][310];
  vector<P> conn0;
  cin >> N >> M;
  REP(i, N) REP(j, N) A[i][j] = (i == j ? 0 : INF);
  REP(i, M) {
    int u, v, l;
    cin >> u >> v >> l;
    u--, v--;
    if (u == 0 || v == 0) {
      if (u > v) swap(u, v);
      conn0.push_back(make_pair(v, l));
    } else {
      A[u][v] = A[v][u] = l;
    }
  }

  REP(i, N) A[0][i] = A[i][0] = INF;
  REP(k, N) REP(i, N) REP(j, N) {
    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
  }

  int ans = INF;
  REP(i, conn0.size()) {
    FOR(j, i+1, conn0.size()) {
      ans = min(ans, A[conn0[i].first][conn0[j].first] + conn0[i].second + conn0[j].second);
    }
  }
  cout << (ans != INF ? ans : -1) << endl;
  return 0;
}
