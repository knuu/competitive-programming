#include <bits/stdc++.h>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int dp[300][300], W[300];

int main() {
  while (true) {
    int N; scanf("%d", &N);
    if (not N) break;
    REP(i, N) scanf("%d", W + i);
    memset(dp, 0, sizeof(dp));
    FOR(w, 2, N + 1) REP(left, N - w + 1) {
      // [left, right]
      int right = left + w - 1;
      if (dp[left + 1][right - 1] == w - 2 and abs(W[left] - W[right]) <= 1) {
        dp[left][right] = w;
      } else {
        FOR(mid, left, right) {
          dp[left][right] = max(dp[left][right], dp[left][mid] + dp[mid + 1][right]);
        }
      }
    }
    printf("%d\n", dp[0][N - 1]);
  }

  return 0;
}
