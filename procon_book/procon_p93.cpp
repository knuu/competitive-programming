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

#define MAX_V 1024

Vi edge[MAX_V];
int color[MAX_V];

bool dfs(int v, int c) {
  if (color[v] != 0) return color[v] == c;

  color[v] = c;
  for (int t : edge[v]) {
    if (!dfs(t, -c)) return false;
  }
  return true;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int V, E;
  cin >> V >> E;
  REP(i, E) {
    int t, s;
    cin >> t >> s;
    edge[t].push_back(s);
    edge[s].push_back(t);
  }

  REP(i, V) {
    if (color[i] == 0 && !dfs(i, 1)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
