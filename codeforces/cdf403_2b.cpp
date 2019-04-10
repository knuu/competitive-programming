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

int N, X[60010], V[60010];

double dist(double mid) {
  double res = 0;
  REP(i, N) res = max(res, abs(mid - X[i]) / V[i]);
  return res;
}

int main() {
  scanf("%d", &N);
  REP(i, N) scanf("%d", &X[i]);
  REP(i, N) scanf("%d", &V[i]);

  double left = 0.0, right = 1e9 + 1;
  REP(i, 1000) {
    double mid1 = (2 * left + right) / 3, mid2 = (left + 2 * right) / 3;
    if (dist(mid1) > dist(mid2)) {
      left = mid1;
    } else {
      right = mid2;
    }
  }

  cout << setprecision(20) << dist(left) << endl;
  return 0;
}
