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

int used[200010];
vector<int> edge[200010];

void dfs(int v) {
  used[v] = 1;
  for (int c : edge[v]) {
    if (not used[c]) dfs(c);
  }
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  REP(i, N) {
    int K; cin >> K;
    REP(j, K) {
      int l; cin >> l; l--;
      edge[i].push_back(N+l);
      edge[N+l].push_back(i);
    }
  }

  dfs(0);
  REP(i, N) {
    if (not used[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
