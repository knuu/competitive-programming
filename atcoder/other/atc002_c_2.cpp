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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  const int INF = 1e9;
  int N; cin >> N; assert(N <= 3000);
  vector<int> W(N + 1, 0);
  REP(i, N) {
    cin >> W[i + 1];
    W[i + 1] += W[i];
  }

  vector<vector<int>> dp(N, vector<int>(N, INF)), root(N, vector<int>(N));
  REP(i, N) dp[i][i] = W[i + 1] - W[i], root[i][i] = i;
  FOR(length, 2, N + 1) REP(left, N - length + 1) {
    int right = left + length - 1, weight = W[right + 1] - W[left];
    FOR(mid, root[left][right - 1], root[left + 1][right] + 1) {
      if (mid + 1 <= right and dp[left][right] > dp[left][mid] + dp[mid + 1][right] + weight) {
        root[left][right] = mid;
        dp[left][right] = dp[left][mid] + dp[mid + 1][right] + weight;
      }
    }
  }
  cout << dp[0][N - 1] - W[N] << endl;
  return 0;
}
