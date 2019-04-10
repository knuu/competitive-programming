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

const ll INF = 1e17;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;

  vector<vector<ll>> A(N, vector<ll>(N, INF));
  REP(i, N) A[i][i] = 0;
  REP(_, M) {
    int a, b, c; cin >> a >> b >> c; a--, b--;
    A[a][b] = A[b][a] = c;
  }

  REP(k, N) REP(i, N) REP(j, N) A[i][j] = min(A[i][j], A[i][k] + A[k][j]);

  int K; cin >> K;
  REP(_, K) {
    int x, y, z; cin >> x >> y >> z; x--, y--;

    if (z < A[x][y]) {
      A[x][y] = A[y][x] = z;
      REP(i, N) REP(j, N) A[i][j] = min(A[i][j], A[i][x] + A[x][j]);
      REP(i, N) REP(j, N) A[i][j] = min(A[i][j], A[i][y] + A[y][j]);
    }

    ll ans = 0;
    REP(i, N) FOR(j, i+1, N) ans += A[i][j];
    cout << ans << endl;
  }
  return 0;
}
