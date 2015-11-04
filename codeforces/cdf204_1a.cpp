#include <bits/stdc++.h>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, cnt = 0;
  double sum = 0.0;

  cin >> N;
  REP(i, 2 * N) {
    double a;
    cin >> a;
    if (a != floor(a)) {
      sum += a - floor(a);
    } else {
      cnt++;
    }
  }

  double ans = 2000;
  if (cnt <= N) {
    FOR(i, N - cnt, N+1) {
      ans = min(ans, abs(i - sum));
    }
  } else {
    REP(i, cnt + 1) {
      ans = min(ans, abs(i - sum));
    }
  }
  printf("%.3lf\n", ans);
  return 0;
}
