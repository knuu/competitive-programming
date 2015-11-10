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
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

ll A[100010], B[100010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll N, K;
  cin >> N >> K;
  REP(i, N/K) cin >> A[i];
  REP(i, N/K) cin >> B[i];

  ll ans = 1, mod = (ll)1e9 + 7LL, p = 1;
  REP(i, K) p *= 10;
  REP(i, N/K) {
    ll total = (p - 1) / A[i] + 1;
    ll ban = ((B[i] + 1) * (p/10) - 1) / A[i] - floor((B[i] * (p/10) - 1.0) / A[i]);
    ans *= total - ban;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
