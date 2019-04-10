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
  ll W, H; cin >> W >> H;

  vector<pair<ll, int>> edge;
  REP(_, W) {
    ll p; cin >> p;
    edge.emplace_back(p, 0);
  }
  REP(_, H) {
    ll q; cin >> q;
    edge.emplace_back(q, 1);
  }

  sort(ALL(edge));
  W++, H++;
  ll ans = 0;
  for (auto e : edge) {
    ll w; int s; tie(w, s) = e;
    //cout << w << ',' << s << ':' << W << ',' << H << endl;
    if (s == 0 and H) {
      ans += H * w;
      W--;
    } else if (s == 1 and W) {
      ans += W * w;
      H--;
    }
  }
  //assert(H == 1 and W == 1);
  cout << ans << endl;

  return 0;
}
