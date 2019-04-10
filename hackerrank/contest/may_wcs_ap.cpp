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
  int T; scanf("%d", &T);
  REP(_, T) {
    int N, K; scanf("%d %d", &N, &K);
    vector<int> per(N, -1), used(N, 0);
    bool flag = false;
    REP(i, N) {
      if (i - K >= 0 and not used[i-K]) {
        per[i] = i-K+1, used[i-K] = 1;
      } else if (i + K < N and not used[i+K]) {
        per[i] = i+K+1, used[i+K] = 1;
      } else {
        flag = true;
        break;
      }
    }
    REP(i, N) {
      if (not used[i]) flag = true;
      if (per[i] == -1) flag = true;
    }
    if (flag) {
      printf("-1\n");
    } else {
      REP(i, N) {
        if (i) printf(" ");
        printf("%d", per[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
