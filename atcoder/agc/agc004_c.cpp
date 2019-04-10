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

  int H, W; cin >> H >> W;

  vector<string> red(H, string(W, '.')), blue(H, string(W, '.'));
  REP(i, H) red[i][0] = blue[i][W-1] = '#';
  REP(i, W-1) red[0][i] = red[H-1][i] = '#';
  FOR(i, 1, H-1) FOR(j, 1, W-1) (i % 2 == 0 ? red : blue)[i][j] = '#';

  REP(i, H) {
    string row; cin >> row;
    REP(j, W) if (row[j] == '#') red[i][j] = blue[i][j] = '#';
  }

  for (string row : red) cout << row << endl;
  cout << endl;
  for (string row : blue) cout << row << endl;
  return 0;
}
