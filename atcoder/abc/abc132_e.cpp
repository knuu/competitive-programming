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

const int INF = 1 << 30;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  vector<vector<int>> edges(N);
  REP(i, M) {
    int u, v; cin >> u >> v; u--, v--;
    edges[u].emplace_back(v);
  }

  int S, T; cin >> S >> T; S--, T--;

  vector<vector<int>> dist(3, vector<int>(N, INF));

  using Tu = tuple<int, int, int>;
  priority_queue<Tu, vector<Tu>, greater<Tu>> pque;
  pque.emplace(0, 0, S);

  while (not pque.empty()) {
    int d, s, v; tie(d, s, v) = pque.top(); pque.pop();
    cerr << v << ' ' << s << ' ' << d << endl;
    if (s == 0 and v == T) {
      cout << d / 3 << endl;
      return 0;
    }
    if (dist[s][v] < d) continue;
    dist[s][v] = d;

    int next_s = (s + 1) % 3;
    for (int c : edges[v]) {
      if (d + 1 < dist[next_s][c]) {
        dist[next_s][c] = d + 1;
        pque.emplace(d+1, next_s, c);
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
