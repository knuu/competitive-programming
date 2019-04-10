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
    assert(N == K);
    double U; cin >> U;
    vector<double> P(N); REP(i, N) cin >> P[i];
    double left = 0.0, right = 1.0;
    REP(_, 1000) {
      double mid = (left + right) / 2;
      double sum = 0;
      REP(i, N) sum += max(0.0, mid - P[i]);
      (sum <= U ? left : right) = mid;
    }
    double ans = 1.0;
    REP(i, N) ans *= max(left, P[i]);
    printf("Case #%d: %.020f\n", t + 1, ans);
  }

  return 0;
}
