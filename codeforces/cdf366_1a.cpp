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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};


int main() {
  int N, Q; scanf("%d %d", &N, &Q);

  int unread = 0, first_max = 0;
  vector<int> apps(N, 0), last_pop(N, -1);
  queue<P> que;

  REP(i, Q) {
    int t, x; scanf("%d %d", &t, &x); x--;
    if (t == 1) {
      apps[x]++;
      que.push(P(x, i));
      unread++;
    } else if (t == 2) {
      unread -= apps[x];
      apps[x] = 0;
      last_pop[x] = i;
    } else {
      if (x >= first_max) {
        REP(_, x-first_max+1) {
          P p = que.front(); que.pop();
          //cout << p.first << ' ' << p.second << endl;
          if (last_pop[p.first] < p.second) {
            unread--;
            apps[p.first]--;
            last_pop[p.first] = p.second;
          }
        }
        first_max = x+1;
      }
    }
    printf("%d\n", unread);
  }
  return 0;
}
