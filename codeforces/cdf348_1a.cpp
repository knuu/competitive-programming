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
  int N, M, Q; cin >> N >> M >> Q;
  vector<vector<int>> mat(N, vector<int>(M, 0));
  vector<vector<int>> query(Q);
  REP(i, Q) {
    int t; cin >> t;
    query[i].push_back(t);
    if (t == 3) {
      int r, c, x; cin >> r >> c >> x; r--, c--;
      query[i].push_back(r);
      query[i].push_back(c);
      query[i].push_back(x);
    } else {
      int x; cin >> x; x--;
      query[i].push_back(x);
    }
  }

  for (int i = Q-1; i >= 0; i--) {
    int t = query[i][0];
    if (t == 1) {
      int r = query[i][1];
      for (int c = M-1; c > 0; c--) swap(mat[r][c], mat[r][c-1]);
    } else if (t == 2) {
      int c = query[i][1];
      for (int r = N-1; r > 0; r--) swap(mat[r][c], mat[r-1][c]);
    } else {
      assert(t == 3);
      int r = query[i][1], c = query[i][2], x = query[i][3];
      mat[r][c] = x;
    }
  }
  REP(i, N) REP(j, M) cout << mat[i][j] << (j == M-1 ? '\n' : ' ');
  return 0;
}
