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
  vector<vector<pair<ll, bool>>> take(N + 1);
  REP(i, M) {
    ll t, l, r; cin >> t >> l >> r;
    take[l - 1].emplace_back(t, true);
    take[r].emplace_back(t, false);
  }
  set<ll> now;
  ll ans = 0;
  REP(i, N) {
    for (auto p : take[i]) {
      int t; bool b; tie(t, b) = p;
      if (b) {
        now.emplace(t);
      } else {
        now.erase(t);
      }
    }
    if (not now.empty()) {
      ans += (ll)*now.rbegin();
    }
  }
  cout << ans << endl;
  return 0;
}
