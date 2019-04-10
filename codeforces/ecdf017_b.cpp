#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
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

  ll a, b, c; cin >> a >> b >> c;
  int m; cin >> m;
  vector<ll> usb, ps;
  REP(_, m) {
    int v; string s; cin >> v >> s;
    (s[0] == 'U' ? usb : ps).push_back(v);
  }
  ll U = usb.size(), P = ps.size();
  usb.push_back(0), ps.push_back(0);
  sort(ALL(usb)), sort(ALL(ps));
  REP(i, U) usb[i+1] += usb[i];
  REP(i, P) ps[i+1] += ps[i];

  pair<ll, ll> ans = make_pair(0, 0);
  for (ll i = 0; i <= c; i++) {
    ll u = min(a + i, U), p = min(b + c - i, P);
    ans = max(ans, make_pair(u + p, -(usb[u] + ps[p])));
  }
  cout << ans.first << ' ' << -ans.second << endl;
  return 0;
}
