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
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> diff(N - 1); REP(i, N - 1) diff[i] = abs(A[i] - A[i + 1]);
  vector<ll> ddiff1(N, 0), ddiff2(N - 1, 0);
  ll sgn = 1;
  REP(i, N - 1) ddiff1[i + 1] = ddiff1[i] + diff[i] * sgn, sgn *= -1;
  sgn = 1;
  FOR(i, 1, N - 1) ddiff2[i] = ddiff2[i - 1] + diff[i] * sgn, sgn *= -1;

  //REP(i, ddiff1.size()) cout << ddiff1[i] << ' '; cout << endl;
  //REP(i, ddiff2.size()) cout << ddiff2[i] << ' '; cout << endl;

  ll r_max = ddiff1[N - 1], ans = INT_MIN;
  for (int i = N - 1; i >= 0; i--) {
    if (i % 2 == 0) ans = max(ans, r_max - ddiff1[i]);
    r_max = max(r_max, ddiff1[i]);
  }

  r_max = ddiff2[N - 2];
  for (int i = N - 2; i >= 0; i--) {
    if (i % 2 == 0) ans = max(ans, r_max - ddiff2[i]);
    r_max = max(r_max, ddiff2[i]);
  }

  cout << ans << endl;
  return 0;
}
