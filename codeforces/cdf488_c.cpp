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

  vector<pair<int, int>> sq[2];
  REP(i, 2) REP(j, 4) {
    int x, y; cin >> x >> y; sq[i].emplace_back(x, y);
  }
  REP(i, 2) sort(ALL(sq[i]));
  int x_left, y_bottom, x_right, y_up;
  tie(x_left, y_bottom) = sq[0][0];
  tie(x_right, y_up) = sq[0][3];
  for (auto p : sq[1]) {
    int x, y; tie(x, y) = p;
    if (x_left <= x and x <= x_right and y_bottom <= y and y <= y_up) {
      cout << "YES" << endl;
      return 0;
    }
  }

  int a = sq[1][0].first + sq[1][0].second;
  int b = sq[1][3].first + sq[1][3].second;
  int c = -sq[1][3].first + sq[1][3].second;
  int d = -sq[1][0].first + sq[1][0].second;

  FOR(x, x_left, x_right + 1) FOR(y, y_bottom, y_up + 1) {
    if (y >= -x + a and y <= -x + b and y >= x + c and y <= x + d) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
