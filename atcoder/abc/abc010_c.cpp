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
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

double dist(int sx, int sy, int gx, int gy, int vx, int vy) {
  return hypot(sx-vx, sy-vy) + hypot(gx-vx, gy-vy);
}

int main() {
  ios_base::sync_with_stdio(false);
  int txa, tya, txb, tyb, T, V;
  cin >> txa >> tya >> txb >> tyb >> T >> V;

  int n;
  cin >> n;
  REP(i, n) {
    int x, y;
    cin >> x >> y;
    if (dist(txa, tya, txb, tyb, x, y) <= T * V) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
