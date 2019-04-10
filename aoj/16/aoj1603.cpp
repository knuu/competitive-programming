#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

pair<int, int> dp[101][50001];
bool used[101][50001];
int N, P[100];

pair<int, int> dfs(int idx, int coins) {
  if (idx == N) return make_pair(0, 0);
  if (used[idx][coins]) return dp[idx][coins];

  used[idx][coins] = true;
  // not buy;
  pair<int, int> ret = dfs(idx + 1, coins);

  // buy only with bills
  int change = (1000 - P[idx] % 1000) % 1000;
  int cnt, money; tie(cnt, money) = dfs(idx + 1, coins + change % 500);
  ret = max(ret, make_pair(cnt + (change >= 500), money - P[idx]));

  // buy with bills & coins to get 500
  if ((P[idx] + 500) % 1000 <= coins) {
    int cnt, money; tie(cnt, money) = dfs(idx + 1, coins - (P[idx] + 500) % 1000);
    ret = max(ret, make_pair(cnt + 1, money - P[idx]));
  }

  return dp[idx][coins] = ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (true) {
    cin >> N;
    if (not N) break;
    REP(i, N) cin >> P[i];
    memset(used, 0, sizeof(used));
    int cnt, money; tie(cnt, money) = dfs(0, 0);
    cout << cnt << ' ' << -money << endl;
  }

  return 0;
}
