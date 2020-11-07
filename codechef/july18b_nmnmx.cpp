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

const ll mod = 1e9 + 7;

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

template <bool prime_mod>
class Combination {
public:
  Combination(const std::size_t max_num, const std::int64_t mod = 1000000007)
    : max_num(max_num), mod(mod) {
    if (max_num == 0) {
      throw std::domain_error("max_num must be larger than 0.");
    }
    if (prime_mod) {
      if (max_num > static_cast<std::size_t>(1e7)) {
        std::stringstream ss;
        ss << max_num << " is too long for prime mod";
        throw std::length_error(ss.str());
      }
      calc_fact();
    } else {
      if (max_num > static_cast<std::size_t>(1e5)) {
        std::stringstream ss;
        ss << max_num << " is too long for non-prime mod";
        std::length_error(ss.str());
      }
      calc_pascal();
    }
  }

  std::int64_t calc(std::int64_t n, std::int64_t k) {
    if (n > static_cast<std::int64_t>(max_num)) {
      std::stringstream ss;
      ss << "n must be smaller than or equal " << max_num;
      throw std::domain_error(ss.str());
    }
    if (n < 0 or k < 0 or n < k) {
      return 1;
    }

    if (prime_mod) {
      return factorial[n] * inv_factorial[k] % mod * inv_factorial[n-k] % mod;
    } else {
      return pascal_tri[n][k];
    }
  }

  //private:
  std::size_t max_num;
  std::int64_t mod;
  std::vector<std::int64_t> factorial, inv_factorial;
  std::vector<std::vector<std::int64_t>> pascal_tri;

  void calc_fact() {
    factorial.resize(max_num+1);
    inv_factorial.resize(max_num+1);
    factorial[0] = factorial[1] = inv_factorial[0] = inv_factorial[1] = 1;
    for (std::size_t i = 2; i <= max_num; i++) {
      factorial[i] = factorial[i-1] * static_cast<std::int64_t>(i) % mod;
    }

    inv_factorial[max_num] = powmod<std::int64_t>(factorial[max_num], mod-2, mod);
    for (std::size_t i = max_num-1; i > 1; i--) {
      inv_factorial[i] = inv_factorial[i+1] * (i+1) % mod;
    }
  }

  void calc_pascal() {
    pascal_tri.resize(max_num+1, std::vector<std::int64_t>(max_num+1, 1));
    for (std::size_t i = 2; i <= max_num; i++) {
      for (std::size_t j = 1; j < i; j++) {
        pascal_tri[i][j] = (pascal_tri[i-1][j-1] + pascal_tri[i-1][j]) % mod;
      }
    }
  }
};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  Combination<false> comb(5000, mod-1);


  int T; cin >> T;
  REP(_, T) {
    int N, K; cin >> N >> K;
    vector<ll> A(N); REP(i, N) cin >> A[i];
    sort(ALL(A));

    ll ans = 1;
    if (N == K) {
      FOR(i, 1, N-1) ans = ans * A[i] % mod;
      cout << ans << endl;
      continue;
    }
    for (ll a : A) {
      ans *= powmod<ll>(a, comb.calc(N-1, K-1), mod);
      ans %= mod;
    }
    REP(i, N-K+1) {
      ans = ans * powmod<ll>(powmod(A[i], mod-2, mod), comb.calc(N-i-1, K-1), mod) % mod;
      ans = ans * powmod<ll>(powmod(A[N-i-1], mod-2, mod), comb.calc(N-i-1, K-1), mod) % mod;
    }
    cout << ans << endl;
  }
  return 0;
}
