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

int t[100010][2];
int diff[100010];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, T;
  cin >> N >> T;
  REP(i, N) REP(j, 2) cin >> t[i][j];
  int M = 0;
  REP(i, N) M += t[i][1];
  if (M > T) {
    cout << -1 << endl;
    return 0;
  }

  REP(i, N) diff[i] = t[i][0] - t[i][1];

  sort(diff, diff + N);

  int ans = N;
  REP(i, N) {
    if (M + diff[i] > T) {
      break;
    }
    M += diff[i];
    ans--;
  }  

  cout << ans << endl;
  return 0;
}
