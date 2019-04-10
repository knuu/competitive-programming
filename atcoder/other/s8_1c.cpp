#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
//typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(ll i=s;i<(ll)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int N, K;
ll D[51];
bool A[51][51];
map<pair<ll, int>, ll> dp;

ll dpdp(ll state, int v) {
  if (state == (1LL << N) - 1LL) return 0;
  if (dp.find(make_pair(state, v)) != dp.end()) return dp[make_pair(state, v)];

  ll ret = 0;
  REP(i, N) {
    if ((state == 0 or A[v][i]) and not (state >> i & 1LL)) {
      ret = max(ret, dpdp(state | 1LL << i, i) + D[i]);
    }
  }
  return dp[make_pair(state, -1)] = ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N >> K;
  REP(i, N) cin >> D[i];
  REP(i, K) {
    int x, y; cin >> x >> y; x--, y--;
    A[x][y] = A[y][x] = true;
  }

  cout << dpdp(0, -1) << endl;
  return 0;
}
