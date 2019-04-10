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

  int N;
  ll xa, ya, xb, yb;
  cin >> N >> xa >> ya >> xb >> yb;
  vector<Pll> ps(N);
  REP(i, N) {
    ll x, y; cin >> x >> y;
    ps[i] = Pll(x, y);
  }

  priority_queue<pair<ll, Pll>> pque;
  ll ans = 0, a1 = 0, a2 = 0;
  REP(i, N) {
    ll x = ps[i].first, y = ps[i].second;
    pque.push(make_pair((x-xa)*(x-xa)+(y-ya)*(y-ya), Pll(x, y)));
    a1 = max(a1, (x-xb)*(x-xb)+(y-yb)*(y-yb));
    a2 = max(a2, (x-xa)*(x-xa)+(y-ya)*(y-ya));
  }
  ans = min(a1, a2);

  ll r2 = 0;
  while (not pque.empty()) {
    ll d = pque.top().first;
    Pll p = pque.top().second; ll x = p.first, y = p.second;
    pque.pop();
    //cout << d << endl;
    ans = min(ans, r2 + d);
    //cout << ans << ',';

    r2 = max(r2, (xb-x)*(xb-x)+(yb-y)*(yb-y));
    //cout << r2 << endl;
    while (not pque.empty() and d == pque.top().first) {
      Pll np = pque.top().second;
      ll x = np.first, y = np.second;
      r2 = max(r2, (xb-x)*(xb-x)+(yb-y)*(yb-y));
      pque.pop();
    }
  }
  cout << ans << endl;
  return 0;
}
