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

const int dx[6] = {-1, -1, 0, 1, 1, 0};
const int dy[6] = {0, 1, 1, 0, -1, -1};

int next_d(int d, int w) {
  if (w == 0) {
    return d % 3 == 1 ? (d + 4) % 6 : (d + 2) % 6;
  } else if (w == 1) {
    return d % 3 == 1 ? (d + 2) % 6 : (d + 4) % 6;
  } else if (w == 2) {
    return d % 3 == 0 ? (d + 2) % 6 : (d + 4) % 6;
  }
}

int solve(int N, int X) {
  vector<vector<int>> tri(N+1, vector<int>(N+1, 0)), wall(N+1, vector<int>(N+1, 0));
  REP(i, N+1) tri[i][0] = 1, wall[i][0] = 0;
  REP(i, N+1) tri[0][i] = 1, wall[0][i] = 1;
  REP(i, N+1) tri[i][N-i] = 1, wall[i][N-i] = 2;

  int ans = 0, d = 1, x = X, y = 0;
  while (1) {
    ans++;
    x += dx[d], y += dy[d];
    //cout << x << ' ' << y << ' ' << d << endl;
    assert(0 <= x and x <= N and 0 <= y and y <= N and x + y <= N);
    if (x == X and y == 0) break;
    if (tri[x][y] == 0) {
      tri[x][y] = 1;
      wall[x][y] = d % 3  == 0 ? 0 : d % 3 == 1 ? 2 : 1;
    } else {
      d = next_d(d, wall[x][y]);
    }
  }
  return ans;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, X; cin >> N >> X;
  assert(N <= 1000);
  cout << solve(N, X) << endl;
  FOR(i, 2, 20) {
    for (int j = 1; j < i; j++) cout << solve(i, j) << (j == i-1 ? '\n' : ' ');
  }
  return 0;
}
