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

int main() {
  ll N;
  cin >> N;
  if (N == 1) {
    cout << N << endl;
    return 0;
  }
  ll ans = 1;
  FOR(i, 2, sqrt(N)+1) {
    int cnt = 0;
    while (N % i == 0) {
      cnt++;
      N /= i;
    }
    if (cnt > 0) ans *= i;
  }
  if (N > 1) ans *= N;
  cout << ans << endl;
  return 0;
}
