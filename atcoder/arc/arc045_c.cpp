#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

vector<vector<P>> edge;
map<int, ll> cnt;

void dfs(int v, int p, int val) {
  for (P e : edge[v]) {
    int c, w; tie(c, w) = e;
    if (c != p) {
      cnt[val^w]++;
      dfs(c, v, val^w);
    }
  }
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, X; cin >> N >> X;
  edge.resize(N);
  REP(_, N-1) {
    int x, y, c; cin >> x >> y >> c; x--, y--;
    edge[x].push_back(make_pair(y, c));
    edge[y].push_back(make_pair(x, c));
  }

  cnt[0]++;
  dfs(0, -1, 0);

  ll ans = 0;
  for (auto p : cnt) {
    int k; ll v; tie(k, v) = p;
    if (cnt.find(k^X) != cnt.end()) ans += v * cnt[k^X];
  }

  if (X == 0) ans -= (ll)N;
  cout << ans/2LL << endl;
  return 0;
}
