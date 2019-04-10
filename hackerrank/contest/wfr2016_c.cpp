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

  int N; cin >> N;
  vector<tuple<ll, ll, int>> ps(N);
  REP(i, N) {
    ll x, y; cin >> x >> y;
    ps[i] = make_tuple(x, y, i);
  }
  sort(ALL(ps));
  ll xa, ya; int ia; tie(xa, ya, ia) = ps[0];
  ll xb, yb; int ib; tie(xb, yb, ib) = ps[1];

  FOR(i, 2, N) {
    ll x, y; int ic; tie(x, y, ic) = ps[i];
    ll xx1 = xa - x, yy1 = ya - y, xx2 = xb - x, yy2 = yb - y;
    if (xx1 * yy2 - xx2  * yy1) {
      cout << ia+1 << ' ' << ib+1 << ' ' << ic+1 << endl;
      return 0;
    }
  }

  return 0;
}
