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
  vector<int> X(N); REP(i, N) cin >> X[i];

  vector<int> counter(100010, 0);
  for (int x : X) counter[x]++;

  vector<vector<int>> mod_counter(M, vector<int>(2, 0));
  REP(i, 100001) {
    mod_counter[i % M][0] += counter[i] % 2;
    mod_counter[i % M][1] += counter[i] / 2;
  }

  int ans = mod_counter[0][0] / 2 + mod_counter[0][1];
  if (M % 2 == 0) ans += mod_counter[M / 2][0] / 2 + mod_counter[M / 2][1];

  for (int i = 1, j = M - 1; i < j; i++, j--) {
    int p = min(mod_counter[i][0], mod_counter[j][0]);
    ans += p;
    mod_counter[i][0] -= p, mod_counter[j][0] -= p;
    int res1 = min(mod_counter[i][1], mod_counter[j][0] / 2);
    ans += res1 + mod_counter[i][1];
    int res2 = min(mod_counter[j][1], mod_counter[i][0] / 2);
    ans += res2 + mod_counter[j][1];
  }
  cout << ans << endl;
  return 0;
}
