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
  int N, p; cin >> N >> p;
  vector<int> L(N+1), R(N+1); REP(i, N) cin >> L[i] >> R[i];
  L[N] = L[0], R[N] = R[0];

  double ans = 0.0;
  REP(i, N) {
    double prob1 = (R[i]/p - (L[i]-1)/p) / (R[i] - L[i] + 1.0);
    double prob2 = (R[i+1]/p - (L[i+1]-1)/p) / (R[i+1] - L[i+1] + 1.0);
    ans += (prob1 + (1 - prob1) * prob2) * 2000;
  }
  cout << setprecision(20) << ans << endl;
  return 0;
}
