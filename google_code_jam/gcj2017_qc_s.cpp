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
  int T; cin >> T;
  REP(t, T) {
    int N, K; cin >> N >> K;
    priority_queue<tuple<int, int, int>> pque;
    pque.emplace(N, 0, N + 1);
    REP(i, K) {
      int v, l, r; tie(v, l, r) = pque.top(); pque.pop();
      int m = l + (v + 1) / 2;
      if (m - l - 1 > 0) pque.emplace(m - l - 1, l, m);
      if (r - m - 1 > 0) pque.emplace(r - m - 1, m, r);
      if (i == K - 1) {
        printf("Case #%d: %d %d\n", t + 1, r - m - 1, m - l - 1);
      }
    }
  }

  return 0;
}
