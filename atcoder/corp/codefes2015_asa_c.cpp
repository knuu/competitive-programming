#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(ll)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

ll A[100010];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll N;
  cin >> N;
  REP(i, N) cin >> A[i];
  ll left = 0, right = 0;
  REP(i, N) right += i * A[i];
  ll ans = right + (N-2) * (N-1) / 2;
  REP(i, N-1) A[i+1] += A[i];
  REP(i, N-1) {
    left += A[i], right -= A[N-1] - A[i];
    // cout << left << ' ' << right << endl;
    if (i & 1) {
      ll l = i, r = N - i - 3;
      ans = min(ans, left + right + l * (l + 1) / 2LL + r * (r + 1) / 2LL);
      // cout << ans << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
