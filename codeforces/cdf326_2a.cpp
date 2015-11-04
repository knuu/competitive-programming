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

int main() {
  int N;
  scanf("%d", &N);
  ll ans = 0;
  ll per_k = 100;
  REP(i, N) {
    int a, p;
    scanf("%d %d", &a, &p);
    per_k = min(per_k, (ll)p);
    ans += ((ll)a) * per_k;
  }
  cout << ans << endl;
  return 0;
}
