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
  int N; ll A, B, K; cin >> N >> A >> B >> K;
  const ll mod = 998244353;
  vector<ll> fact(N + 1), rev_fact(N + 1);
  fact[0] = fact[1] = 1;
  rev_fact[0] = rev_fact[1] = inv(1LL, mod);
  FOR(i, 2, N + 1) {
    fact[i] = (fact[i - 1] * (ll)i) % mod;
    rev_fact[i] = inv(fact[i], mod);
  }
  ll ans = 0;
  for (ll i = 0; i <= N and i * A <= K; ++i) {
    if ((K - A * i) % B == 0 and (K - A * i) / B <= N) {
      int x = i, y = (K - A * i) / B;
      ans += fact[N] * rev_fact[x] % mod * rev_fact[N - x] % mod * fact[N] % mod * rev_fact[y] % mod * rev_fact[N - y] % mod;
      ans %= mod;
    }
  }
  cout << ans << endl;

  return 0;
}
