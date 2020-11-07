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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, Q; cin >> N >> Q;
  vector<vector<int>> A(N, vector<int>(N, 0));
  REP(_, Q) {
    int q; cin >> q;
    if (q == 1) {
      int a, b; cin >> a >> b; a--, b--;
      A[a][b] = 1;
    } else if (q == 2) {
      int a; cin >> a; a--;
      REP(i, N) if (A[i][a]) A[a][i] = 1;
    } else {
      int a; cin >> a; a--;
      set<int> follow;
      REP(i, N) {
        if (A[a][i] == 1) {
          REP(j, N) if (j != a and A[i][j]) follow.insert(j);
        }
      }
      for (int x : follow) A[a][x] = 1;
    }
  }

  REP(i, N) {
    REP(j, N) cout << (A[i][j] ? 'Y' : 'N');
    cout << endl;
  }

  return 0;
}
