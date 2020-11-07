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

  int N; cin >> N;
  map<ll, vector<int>> mp;
  REP(i, N) {
    ll a; cin >> a;
    mp[a].emplace_back(i);
  }

  vector<ll> height, counter;
  vector<int> indices;
  int min_idx = N;
  ll cnt = 0;
  for (auto it = mp.rbegin(); it != mp.rend(); it++) {
    for (int idx : it->second) {
      min_idx = min(min_idx, idx);
    }
    cnt += it->second.size();
    height.emplace_back(it->first);
    counter.emplace_back(cnt);
    indices.emplace_back(min_idx);
  }

  height.emplace_back(0);

  vector<ll> ans(N, 0);
  REP(i, counter.size()) {
    ans[indices[i]] += (height[i] - height[i+1]) * counter[i];
  }
  for (ll a : ans) cout << a << endl;

  return 0;
}
