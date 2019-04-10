#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(ll i=s;i<(ll)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll X; cin >> X;
  vector<Pll> ans;
  for (ll R = 1; ; R++) {
    ll k = 3LL * R * (R + 1LL), b = 6LL * X + R * (R + 1LL) * (R - 1LL);
    if (R > 1.0 * b / k) break;
    assert(b > 0);
    if (b % k == 0) {
      //cout << b << ' ' << k << endl;
      ll C = b / k;
      ans.push_back(Pll(R, C));
      if (R != C) ans.push_back(Pll(C, R));
    }
  }
  sort(ALL(ans));
  cout << ans.size() << endl;
  for (Pll p : ans) {
    cout << p.first << ' ' << p.second << endl;
  }      
  return 0;
}
