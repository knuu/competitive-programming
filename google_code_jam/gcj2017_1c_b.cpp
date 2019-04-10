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

  int T; cin >> T;
  REP(t, T) {
    int ac, aj; cin >> ac >> aj;
    assert(ac + aj <= 2);
    if ((ac == 1 and aj == 1) or ac + aj <= 1) {
      REP(_, ac + aj) {
        int s, t; cin >> s >> t;
      }

      printf("Case #%d: 2\n", t + 1);
    } else {
      int s1, t1, s2, t2; cin >> s1 >> t1 >> s2 >> t2;
      if (s1 > s2) swap(s1, s2), swap(t1, t2);
      if (min(t2 - s1, t1 + 1440 - s2) <= 720) {
        printf("Case #%d: 2\n", t + 1);
      } else {
        printf("Case #%d: 4\n", t + 1);
      }
    }
  }

  return 0;
}
