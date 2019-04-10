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

const ll mod = 1000000007;

int N;
int C[260];
ll dp_forest[260][260], dp_tree[260][260];

ll tree(int L, int R);
ll forest(int L, int R);

ll tree(int L, int R) {
  if (L >= R) return 1;
  if (dp_tree[L][R] != -1) return dp_tree[L][R];
  return dp_tree[L][R] = forest(L + 1, R) % mod;
}

ll forest(int L, int R) {
  if (L >= R) return 1;
  if (dp_forest[L][R] != -1) return dp_forest[L][R];

  ll ret = tree(L, R);
  FOR(i, L+1, R+1) {
    if (C[L] < C[i]) {
      ret += tree(L, i-1) % mod * forest(i, R) % mod;
      ret %= mod;
    }
  }
  return dp_forest[L][R] = ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  REP(i, N) cin >> C[i];

  memset(dp_forest, -1, sizeof(dp_forest));
  memset(dp_tree, -1, sizeof(dp_tree));

  REP(i, N) dp_tree[i][i] = 1;

  if (C[0] != 1) {
    cout << 0 << endl;
  } else {
    cout << tree(0, N-1) << endl;
  }
  return 0;
}
