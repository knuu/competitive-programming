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
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll N, x;
  cin >> N >> x;

  ll ans = 0;
  FOR(i, 1, N+1) {
    if (x <= i*N && x % i == 0) ans++;
  }

  cout << ans << endl;
  return 0;
}
