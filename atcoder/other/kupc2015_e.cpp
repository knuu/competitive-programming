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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  REP(t, T) {
    double H, W;
    cin >> H >> W;
    if (H > W) swap(H, W);
    double high = H, low = 0.0;
    REP(i, 1000) {
      double mid = (high + low) / 2.0;
      double x = (W * W + mid * mid - 2 * mid * H) / (2 * W);
      double b = hypot(W, mid), a = hypot(x, H);
      if (b < a) {
	low = mid;
      } else {
	high = mid;
      }
    }
    double x = (W * W + low * low - 2 * low * H) / (2 * W);
    cout << setprecision(20) << min(hypot(W, low), hypot(x, H)) << endl;
  }
  return 0;
}
