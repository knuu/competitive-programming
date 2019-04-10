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
const ll mod = 1000000007;

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

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, K; cin >> N >> K;
  ll ans = 0;
  ll s = powmod<ll>(2, K-1, mod);
  for (int i = 0; i + K < N; i++) {
    ans += s * ((powmod<ll>(2, N - (i+K), mod) - 1LL + mod) % mod) % mod;
    ans %= mod;
    //cout << ans << endl;
  }
  cout << (powmod<ll>(2, N, mod) - ans + mod) % mod << endl;
  return 0;
}
