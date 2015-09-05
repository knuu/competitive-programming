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
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

int main() {
  ll sticks[3], l;
  REP(i, 3) cin >> sticks[i];
  cin >> l;

  ll ans = (l + 3) * (l + 2) * (l + 1) / 6;
  REP(i, l+1) {
    REP(j, 3) {
      if (2 * sticks[j] - accumulate(sticks, sticks + 3, 0) + i >= 0) {
	ll not_tri = min(2 * sticks[j] - accumulate(sticks, sticks + 3, 0) + i, l - i);
	ans -= (not_tri + 2) * (not_tri + 1) / 2;
      }
    }
  }
  cout << ans << endl;
  
  return 0;
}
