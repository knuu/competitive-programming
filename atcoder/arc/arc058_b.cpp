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

ll fact[(int)1e6+10], inv_f[(int)1e6+10];

template <typename T>
T comb(int n, int k, T mod) {
  assert(0 <= k and k <= n);
  return fact[n] * inv_f[k] % mod * inv_f[n-k] % mod;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int H, W, A, B; cin >> H >> W >> A >> B;
  const ll mod = 1e9+7;

  fact[0] = fact[1] = 1;
  FOR(i, 2, 1e6+1) fact[i] = fact[i-1] * i % mod;
  inv_f[(int)1e6] = inv(fact[(int)1e6], mod);
  for (int i = (int)1e6; i > 0; i--) inv_f[i-1] = inv_f[i] * i % mod;


  ll ans = 0;
  FOR(i, B, W) {
    ans += comb(H-A-1+i, i, mod) * comb(A+W-i-2, A-1, mod) % mod;
    ans %= mod;
  }


  cout << ans << endl;
  return 0;
}
