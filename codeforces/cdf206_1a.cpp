#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

ll W[100010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll N, L, R, QL, QR;
  cin >> N >> L >> R >> QL >> QR;
  W[0] = 0;
  REP(i, N) cin >> W[i+1];
  REP(i, N) W[i+1] += W[i];

  // [?, mid] -> left, (mid, ?) -> right
  ll ans = R * W[N] + (N - 1) * QR;
  FOR(mid, 1, N+1) {
    ll left = mid, right = N - mid;
    if (left < right) {
      ll suc = max<ll>(0LL, right - left - 1LL);
      ans = min(ans, L * W[left] + R * (W[N] - W[left]) + QR * suc);
    } else {
      ll suc = max<ll>(0LL, left - right - 1LL);
      ans = min(ans, L * W[left] + R * (W[N] - W[left]) + QL * suc);
    }
  }
  cout << ans << endl;
  
  return 0;
}
