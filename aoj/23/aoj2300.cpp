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

double sq(double x) { return x * x; }

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  vector<double> L(N), A(N), B(N);
  REP(i, N) cin >> L[i] >> A[i] >> B[i];
  double ans = 0.0;
  REP(bit, 1<<N) {
    if (__builtin_popcount(bit) != M) continue;
    double cand = 0.0;
    REP(i, N)  FOR(j, i+1, N) if ((bit >> i & 1) and (bit >> j & 1)) cand += sq(L[i] - L[j]) + sq(A[i] - A[j]) + sq(B[i] - B[j]);
    ans = max(ans, cand);
  }
  cout << setprecision(20) << ans << endl;
  return 0;
}
