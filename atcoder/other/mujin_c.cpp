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
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, M; cin >> N >> M;
  vector<vector<bool>> adj(N, vector<bool>(N, false));
  REP(i, M) {
    int x, y; cin >> x >> y; x--, y--;
    adj[x][y] = adj[y][x] = true;
  }

  int ans = 0;
  REP(bit, 1 << N) {
    vector<vector<int>> edge(N);
    REP(i, N) FOR(j, i+1, N) {
      if ((bit >> i & 1) != (bit >> j & 1) and adj[i][j]) {
        edge[i].push_back(j);
        edge[j].push_back(i);
      }
    }
    vector<bool> used(N, false);
    queue<int> que;
    que.push(0);
    while (not que.empty()) {
      int v = que.front(); que.pop();
      if (used[v]) continue;
      used[v] = true;
      for (int c : edge[v]) {
        if (not used[c]) que.push(c);
      }
    }
    bool flag = true;
    REP(i, N) flag &= used[i];
    if (flag) ans++;
  }
  cout << ans / 2 << endl;
  return 0;
}
