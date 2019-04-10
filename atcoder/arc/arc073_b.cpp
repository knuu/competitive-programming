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

int N;
ll W;
vector<ll> weight;
vector<int> value;
int dp[101][101][301];

int dfs(int i, int k, ll w) {
  if (i == N) return 0;
  if (dp[i][k][w] != -1) return dp[i][k][w];
  int ret = 0;
  if (w + (ll)k * weight[0] + weight[i] <= W) ret = max(ret, dfs(i + 1, k + 1, w + weight[i] - weight[0]) + value[i]);
  ret = max(ret, dfs(i + 1, k, w));
  return dp[i][k][w] = ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  memset(dp, -1, sizeof(dp));
  cin >> N >> W;
  weight.resize(N); value.resize(N);
  REP(i, N) cin >> weight[i] >> value[i];

  cout << dfs(0, 0, 0) << endl;
  return 0;
}
