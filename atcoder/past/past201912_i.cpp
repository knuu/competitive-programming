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
  int N, M; cin >> N >> M;
  vector<pair<int, ll>> items;
  REP(i, M) {
    string S; ll C; cin >> S >> C;
    int bits = 0;
    REP(j, N) if (S[j] == 'Y') bits |= (1 << j);
    items.emplace_back(bits, C);
  }

  const ll INF = 1e18;
  vector<ll> dp(1 << 10, INF);
  dp[0] = 0;
  REP(state, 1 << N) {
    for (auto&& p : items) {
      int bits; ll c; tie(bits, c) = p;
      dp[state | bits] = min(dp[state | bits], dp[state] + c);
    }
  }

  cout << (dp[(1 << N) - 1] == INF ? -1 : dp[(1 << N) - 1]) << endl;
  return 0;
}
