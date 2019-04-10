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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  ll x, y; cin >> x >> y;
  double min_r = 1e16, max_r = 0;
  vector<pair<ll, ll>> points(N+1);
  REP(i, N) {
    ll a, b; cin >> a >> b;
    double r = (a-x)*(a-x) + (b-y)*(b-y);
    points[i] = make_pair(a-x, b-y);
    min_r = min(min_r, r);
    max_r = max(max_r, r);
  }
  points[N] = points[0];
  REP(i, N) {
    pair<ll, ll> p1 = points[i], p2 = points[i+1];
    ll a1 = p1.first, b1 = p1.second, a2 = p2.first, b2 = p2.second;
    if (a1 > a2) swap(a1, a2), swap(b1, b2);
    if (b1 == b2) {
      if (a1 <= x and x <= a2) {
	double r = b1 * b1;
	min_r = min(min_r, r);
	max_r = max(max_r, r);
      }
    } else if (a1 == a2) {
      if (b1 > b2) swap(b1, b2);
      if (b1 <= y and y <= b2) {
	double r = a1 * a1;
	min_r = min(min_r, r);
	max_r = max(max_r, r);
      }
    } else {
      double m = 1.0 * (b2 - b1) / (a2 - a1);
      double xx = (a1 * m * m - b1 * m) / (m * m + 1.0), yy = - (a1 * m - b1) / (m * m + 1.0);
      if (a1 <= xx and xx <= a2) {
	double r = xx * xx + yy * yy;
	min_r = min(min_r, r);
	max_r = max(max_r, r);
      }
    }
  }
    
  cout << setprecision(20) << (max_r - min_r) * acos(-1) << endl;
  return 0;
}
