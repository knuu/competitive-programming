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
  ll N; cin >> N;
  vector<ll> C(N); REP(i, N) cin >> C[i];
  ll min_elm = 1e10, min_even_elm = 1e10;
  REP(i, N) {
    if (i % 2 == 0) {
      min_even_elm = min(C[i], min_even_elm);
    }
    min_elm = min(C[i], min_elm);
  }
  ll cnt = 0, even_cnt = 0;
  int Q; cin >> Q;
  ll ans = 0;
  REP(qq, Q) {

    int q; cin >> q;
    if (q == 1) {
      int x; ll a; cin >> x >> a; x--;

      ll now = C[x] - cnt - (x % 2 == 0) * even_cnt;
      ll next = now - a;
      if (next >= 0) {
        ans += a;
        C[x] -= a;
        min_elm = min(min_elm, next);
        if (x % 2 == 0) min_even_elm = min(min_even_elm, next);
      }
    } else if (q == 2) {
      ll a; cin >> a;
      if (min_even_elm < a) continue;
      ans += (ll)(N + 1) / 2 * a;
      min_even_elm -= a;
      min_elm = min(min_elm, min_even_elm);
      even_cnt += a;
    } else {
      ll a; cin >> a;
      if (min_elm < a) continue;
      ans += (ll)N * a;
      min_elm -= a;
      cnt += a;
      min_even_elm -= a;
    }

  }

  cout << ans << endl;
  return 0;
}
