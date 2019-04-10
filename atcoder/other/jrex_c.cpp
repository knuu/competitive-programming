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

const ll mod = 1e9 + 7;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll N, A, B; cin >> N >> A >> B;
  if (A > B) swap(A, B);
  vector<ll> S(N+1); REP(i, N) cin >> S[i+1];
  S[0] = -1e18;
  REP(i, N-1) {
    if (S[i+2] - S[i] < A) {
      cout << 0 << endl;
      return 0;
    }
  }

  vector<ll> dp(N+1), imos(N+2);
  dp[0] = imos[1] = 1;
  int left = 0;

  REP(i, N) {
    int ub = upper_bound(ALL(S), S[i+1] - B) - S.begin();
    if (left < ub) dp[i+1] = imos[i+2] = (imos[ub] - imos[left] + mod) % mod;
    imos[i+2] += imos[i+1];
    imos[i+2] %= mod;
    if (S[i+1] - S[i] < A) left = i;
  }

  ll ans = 0;
  FOR(i, left, N+1) {
    ans += dp[i];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
