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

  int N, A[128];
  cin >> N;
  REP(i, N) cin >> A[i];

  REP(i, N-1) A[i+1] += A[i];

  if (A[N-1] % N != 0) {
    cout << -1 << endl;
    return 0;
  }

  int ans = 0;
  REP(i, N-1) {
    if ((i+1) * (A[N-1] - A[i]) != (N-i-1) * A[i]) ans++;
  }

  cout << ans << endl;
  return 0;
}
