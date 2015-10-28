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

ll A[100010], B[100010];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll N, M, X, Y;
  cin >> N >> M >> X >> Y;
  REP(i, N) cin >> A[i];
  REP(i, M) cin >> B[i];
  ll now = A[0], ans = 0;
  while (true) {
    auto b_lb = lower_bound(B, B + M, now + X);
    if (b_lb == B + M) {
      break;
    } else {
      ans++;
    }
    auto a_lb = lower_bound(A, A + N, *b_lb + Y);
    if (a_lb == A + N) {
      break;
    } else {
      now = *a_lb;
    }
  }
  cout << ans << endl;    
  return 0;
}
