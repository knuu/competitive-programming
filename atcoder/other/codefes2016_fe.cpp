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

  int N, A; cin >> N >> A;
  assert(N <= 1000000 and A <= 1000000);
  vector<int> dp(2 * N + 1);
  REP(i, 2 * N + 1) dp[i] = i;
  FOR(i, 1, N) {
    for (int j = 0; j <= 2 * N; j += i) dp[j] = min(dp[j], dp[i] + A + j / i);
  }
  cout << *min_element(dp.begin() + N, dp.end()) << endl;
  return 0;
}
