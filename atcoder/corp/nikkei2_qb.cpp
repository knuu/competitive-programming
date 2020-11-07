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
const ll mod = 998244353;

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
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N; cin >> N;
  vector<ll> D(N); REP(i, N) cin >> D[i];
  if (D[0] != 0) {
    cout << 0 << endl;
    return 0;
  }
  ll max_D = *max_element(ALL(D));
  vector<ll> d_map(max_D + 1, 0);
  for (ll d : D) d_map[d]++;
  if (d_map[0] != 1) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  FOR(i, 1, max_D + 1) {
    ans *= powmod<ll>(d_map[i-1], d_map[i], mod);
    ans %= mod;
  }
  cout << ans << endl;


  return 0;
}
