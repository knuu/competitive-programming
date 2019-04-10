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
  vector<vector<char>> board(4, vector<char>(4));
  REP(i, 4) REP(j, 4) cin >> board[i][j];
  for (int i = 3; i >= 0; i--) {
    for (int j = 3; j >= 0; j--) {
      cout << board[i][j] << (j == 0 ? '\n' : ' ');
    }
  }

  return 0;
}
