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
  // use scanf in CodeForces!

  int N;
  scanf("%d", &N);
  int ans = 0, cont = 0, prev = 0;
  REP(i, N) {
    int t;
    scanf("%d", &t);
    if (prev <= t) {
      cont++;
    } else {
      ans = max(ans, cont);
      cont = 1;
    }
    prev = t;
  }
  ans = max(ans, cont);
  printf("%d\n", ans);
  return 0;
}
