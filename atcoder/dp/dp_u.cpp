#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
// typedef tuple<int, int, int> T;
#define FOR(i, s, x) for (int i = s; i < (int)(x); i++)
#define REP(i, x) FOR(i, 0, x)
#define ALL(c) c.begin(), c.end()
#define DUMP(x) cerr << #x << " = " << (x) << endl
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int N;
ll dp[1 << 16], A[16][16];

int main() {
  scanf("%d", &N);
  REP(i, N) REP(j, N) scanf("%lld", &A[i][j]);
  REP(state, 1 << N) {
    REP(i, N) FOR(j, i + 1, N) {
      // if ((state >> i & 1) and (state >> j & 1)) dp[state] += A[i][j];
      dp[state] += A[i][j] * (state >> i & 1) * (state >> j & 1);
    }
    for (int sub = (state - 1) & state; sub > 0; sub = state & (sub - 1)) {
      int not_sub = state & ~sub;
      if (sub < not_sub) break;
      dp[state] = max(dp[state], dp[sub] + dp[not_sub]);
    }
  }
  printf("%lld\n", dp[(1 << N) - 1]);
  return 0;
}
