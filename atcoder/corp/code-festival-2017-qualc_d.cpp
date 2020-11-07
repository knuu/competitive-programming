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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string S;
  std::cin >> S;
  int N = S.size();

  std::vector<int> dp(1 << 26, N);
  dp[0] = 0;
  int bit = 0;
  int ans;
  for (int i = 0; i < N; i++) {
    bit ^= 1 << (S[i] - 'a');
    ans = dp[bit] + 1;
    for (int j = 0; j < 26; j++) {
      ans = min(ans, dp[bit ^ (1 << j)] + 1);
    }
    dp[bit] = min(dp[bit], ans);
  }
  cout << ans << endl;
  return 0;
}
