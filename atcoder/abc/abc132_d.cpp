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

template <typename T>
T comb(T n, T k, T mod) {
  assert (0 <= k && k <= n);
  T ret = 1;
  for (T i = 0; i < k; i++) {
    ret *= n - i;
    ret %= mod;
    ret *= inv(i+1);
    ret %= mod;
  }
  return ret;
}


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, K; cin >> N >> K;

  const ll mod = 1e9 + 7;

  vector<ll> fact(N + 10, 1), fact_inv(N + 10, 1);
  FOR(i, 2, N + 10) {
    fact[i] = (fact[i-1] * i) % mod;
    fact_inv[i] = inv(fact[i], mod);
  }

  FOR(i, 1, K+1) {
    ll blue = K, red = N - K;
    if (red < 0) {
      cout << 0 << endl;
      continue;
    }

    ll red1_P_i = fact[red + 1] * fact_inv[red + 1 - i] % mod * fact_inv[i] % mod;
    ll m = blue - i + (i - 1);
    ll m_C_i1 = fact[m] * fact_inv[i-1] % mod * fact_inv[m-(i-1)] % mod;
    cerr << red1_P_i << ' ' << m_C_i1 << ' ' << endl;
    cout << red1_P_i * m_C_i1 % mod << endl;
  }

  return 0;
}
