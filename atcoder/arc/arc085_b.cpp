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
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int N, Z, W;
int A[2000], dp[2001][2001];

int dfs(int z, int w) {
  if (z == N or w == N) {
    return abs((z == 0 ? Z : A[z - 1]) - (w == 0 ? W : A[w - 1]));
  } else if (dp[z][w] != -1) {
    return dp[z][w];
  }
  int ret;
  if (z <= w) {
    ret = 0;
    FOR(i, w + 1, N + 1) ret = max(ret, dfs(i, w));
  } else {
    ret = (int)2e9;
    FOR(i, z + 1, N + 1) ret = min(ret, dfs(z, i));
  }
  return dp[z][w] = ret;
}

int main() {
  cin >> N >> Z >> W;
  REP(i, N) cin >> A[i];
  memset(dp, -1, sizeof(dp));
  cout << dfs(0, 0) << endl;

  return 0;
}
