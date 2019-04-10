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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

Vi edge[6];
int color[6];

void dfs(int v, int c) {
  if (color[v]) return ;
  color[v] = c;
  for (int ch : edge[v]) dfs(ch, c);    
}  

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  REP(_, T) {
    int N, K, M;
    cin >> N >> K >> M;
    assert(N <= 6);
    vector<P> ee;
    REP(i, N) FOR(j, i+1, N) ee.push_back(P(i, j));
    int B = N * (N - 1) / 2;
    int ans = 0;
    REP(b, (1 << B) - 1) {
      REP(i, N) edge[i].clear();
      REP(i, B) {
	if (b >> i & 1) {
	  P e = ee[i];
	  int a = e.first, b = e.second;
	  edge[a].push_back(b);
	  edge[b].push_back(a);
	}
      }
      fill(color, color + N, 0);
      int cnt = 0;
      REP(i, N) if (!color[i]) dfs(i, ++cnt);
      if (cnt == K) ans++;
    }
    cout << ans % M << endl;
  }  
  return 0;
}
