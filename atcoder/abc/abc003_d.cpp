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

template <typename T>
T powmod(T n, T k, T mod) {
  if (k == 0) {
    return 1;
  } else if (k % 2 == 0) {
    return powmod(n * n % mod, k / 2, mod);
  } else {
    return n * powmod(n, k-1, mod) % mod;
  }
}

template <typename T>
T inv(T x, T mod) {
  return powmod(x, mod-2, mod);
}


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  const ll mod = 1e9 + 7;

  int R, C, X, Y, D, L; cin >> R >> C >> X >> Y >> D >> L;
  vector<ll> fact(R * C + 1), inv_fact(R * C + 1);
  fact[0] = fact[1] = 1;
  inv_fact[0] = inv_fact[1] = inv(1LL, mod);

  FOR(i, 2, R * C + 1) {
    //cout << i << endl;
    fact[i] = (ll)i * fact[i - 1] % mod;
    inv_fact[i] = inv(fact[i], mod);
  }

  int ans = 0;
  REP(state, 1 << 4) {
    int x = X - (state >> 0 & 1) - (state >> 1 & 1);
    int y = Y - (state >> 2 & 1) - (state >> 3 & 1);
    if (x < 0 or y < 0 or x * y < D + L) {
      continue;
    }
    ll cnt = fact[x * y] * inv_fact[D] % mod * inv_fact[L] % mod * inv_fact[x * y - D - L] % mod;
    if (__builtin_popcount(state) % 2 == 0) {
      ans = (ans + cnt) % mod;
    } else {
      ans = (ans + mod - cnt) % mod;
    }
  }
  cout << ans * (ll)(R - X + 1) % mod * (ll)(C - Y + 1) % mod << endl;
  return 0;
}
