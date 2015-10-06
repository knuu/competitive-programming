#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

Vi edge[100010];
int child[100010];
int ans[100010];
int N;

void dfs1(int s, int par) {
  for (int c : edge[s]) {
    if (c != par) {
      dfs1(c, s);
      child[s] += child[c] + 1;
    }
  }
}

void dfs2(int s, int par) {
  for (int c : edge[s]) {
    if (c != par) {
      dfs2(c, s);
      ans[s] = max(ans[s], child[c] + 1);
    } else {
      if (par < 0) continue;
      ans[s] = max(ans[s], N - child[s] - 1);
    }
  }
}
  

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;

  FOR(s, 1, N) {
    int t;
    cin >> t;
    edge[s].push_back(t);
    edge[t].push_back(s);
  }

  dfs1(0, -1);
  dfs2(0, -1);

  REP(i, N) cout << ans[i] << endl;
  return 0;
}
