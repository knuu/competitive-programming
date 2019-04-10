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
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M, S; cin >> N >> M >> S;
  vector<vector<int>> edge(N);

  REP(i, M) {
    int u, v; cin >> u >> v; u--, v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  vector<int> max_v(N, -1);
  priority_queue<pair<int, int>> pque;
  pque.push(make_pair(N, S-1));

  while(not pque.empty()) {
    int v, c; tie(c, v) = pque.top(); pque.pop();
    if (max_v[v] != -1) continue;
    max_v[v] = c;
    for (int next : edge[v]) {
      if (max_v[next] == -1) {
        pque.push(make_pair(min(max_v[v], v), next));
      }
    }
  }

  REP(i, N) if (max_v[i] >= i) cout << i+1 << endl;

  return 0;
}
