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

int D[32][32];
const int INF = 1<<29;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  REP(t, T) {
    int N;
    cin >> N;
    REP(i, N) REP(j, N) {
      int d;
      cin >> d;
      if (d == -1) d = INF;
      D[i][j] = d;
    }

    bool is_ok = true;
    REP(i, N) if (D[i][i]) is_ok = false;
    REP(k, N) REP(i, N) REP(j, N) {
      if (D[i][k] + D[k][j] < D[i][j]) is_ok = false;
    }
    cout << (is_ok ? "YES" : "NO") << endl;
  }
  return 0;
}
