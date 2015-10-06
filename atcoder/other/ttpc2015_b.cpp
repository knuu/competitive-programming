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

int A[128];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, B, C;
  cin >> N >> B >> C;
  REP(i, N) cin >> A[i];

  int ans = 0;
  REP(i, N) {
    int use = min(C, B);
    C -= use;
    ans += A[N-i-1] * use;
  }

  cout << ans << endl;

  return 0;
}
