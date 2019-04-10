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

  ll N, H, A, B, C, D, E; cin >> N >> H >> A >> B >> C >> D >> E;

  ll ans = 1e18;
  REP(y, N+1) {
    ll x = max<ll>(0, (ll)ceil((E*N - H - 1.0*(D+E)*y+1.0)/(B+E)));
    //cout << y << ',' << x << ':' << A*x+C*y << endl;
    ans = min(ans, A*x + C*y);
  }
  cout << ans << endl;

  return 0;
}
