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

int N, M;
vector<P> edge[100010];
int color[100010];

bool is_prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int dfs(int v, int p, int r, int prd) {
  int ret = 0;
  assert(M != 0);
  if (v > r && prd == 0) ret++;
  for (P c : edge[v]) {
    int cv = c.first, cc = c.second;
    if (p != cv) ret += dfs(cv, v, r, (prd * cc) % M);
  }
  return ret;
}

ll dfs2(int v, int p, int col) {
  ll ret = 1;
  color[v] = col;
  for (P c : edge[v]) {
    int cv = c.first;
    if (cv != p && !color[cv]) ret += dfs2(cv, v, col);
  }
  return ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  //REP(i, 100) if (is_prime(i)) cout << i << ' ';
  //cout << endl;
  cin >> N >> M;
  if (is_prime(M)) {
    REP(i, N-1) {
      int a, b, c;
      cin >> a >> b >> c; a--, b--;
      if (c % M != 0) {
	edge[a].push_back(P(b, c));
	edge[b].push_back(P(a, c));
      }
    }
    ll n = N, ans = n * (n - 1) / 2;
    int cnt = 0;
    REP(i, N) {
      if (!color[i]) {
	ll c = dfs2(i, -1, ++cnt);
	assert(c >= 0 && c * (c - 1) / 2LL >= 0);
	ans -= c * (c - 1) / 2LL;
      }
    }
    cout << ans << endl;
  } else if (N <= 1000) {
    REP(i, N - 1) {
      int a, b, c;
      cin >> a >> b >> c; a--, b--;
      assert(a < N && b < N);
      edge[a].push_back(P(b, c % M));
      edge[b].push_back(P(a, c % M));
    }

    int ans = 0;
    REP(i, N) ans += dfs(i, -1, i, 1);
    cout << ans << endl;
  }

  return 0;
}
