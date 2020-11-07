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

  int N; cin >> N;
  vector<ll> X(N); REP(i, N) cin >> X[i];
  ll fact_N1 = 1;
  vector<ll> invs(N+1);
  invs[0] = invs[1] = 1;
  FOR(i, 2, N + 1) {
    if (i <= N-1) fact_N1 = (fact_N1 * i) % mod;
    invs[i] = inv<ll>(i, mod);
  }
  ll ans = 0;

  REP(i, N-1) {
    if (i > 0) ans += (1 - invs[i+1] + mod) * X[i] % mod;
    ans %= mod;
    if (i < N-2) ans += (-1 + invs[N-i-1] + mod) % mod * X[i] % mod;
    ans %= mod;
    ans += (X[N-1] - X[i]) * invs[N-i-1] % mod;
    ans %= mod;
  }
  cout << (ans * fact_N1 % mod) << endl;
  return 0;
}
