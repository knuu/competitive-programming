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
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

ll f(ll k) {
  ll ret = 0, n = k, i=0;
  while (n) {
    ret += (n%10)*pow(k, i);
    n /= 10;
    i++;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  ll N;
  cin >> N;

  for (ll i = 10000; i >= 10; i--) {
    if (N == f(i)) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
    
  return 0;
}
