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

int weight[1001000];

int main() {
  int N;
  scanf("%d", &N);
  REP(i, N) {
    int w;
    scanf("%d", &w);
    weight[w]++;
  }

  int ans = 0;
  REP(i, 1000100) {
    if (weight[i] % 2) ans++;
    weight[i+1] += weight[i] / 2;
  }
  cout << ans << endl;
  return 0;
}
