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
T inv(T x, T mod = 1e9 + 7) {
  return powmod(x, mod-2, mod);
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  const ll mod = 1e9 + 7;

  int N; cin >> N;
  vector<ll> fact(N), inv_fact(N);
  fact[0] = fact[1] = 1;
  inv_fact[0] = inv_fact[1] = inv(1);
  FOR(i, 2, N) {
    fact[i] = (fact[i - 1] * (ll)i) % mod;
    inv_fact[i] = inv(fact[i]);
  }

  ll ans = 0, prev = 0;

  REP(k, N) {
    if (k - 1 >= 0 and N - k - 1 >= 0 and k - 1 >= N - k - 1) {
      ll now = fact[k - 1] * inv_fact[2 * k - N] % mod * fact[k] % mod;
      ans += (now - prev + mod) % mod * k % mod;
      ans %= mod;
      prev = now;
    }
  }
  cout << ans << endl;
  return 0;
}
