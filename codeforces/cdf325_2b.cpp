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

  int N, row[2][64], cross[64];
  row[0][0] = row[1][0] = 0;
  cin >> N;
  REP(i, 2) REP(j, N-1) cin >> row[i][j+1];
  REP(i, N) cin >> cross[i];
  REP(i, 2) REP(j, N-1) row[i][j+1] += row[i][j];

  Vi ans;
  REP(i, N) {
    ans.push_back(row[0][i] + cross[i] + (row[1][N-1] - row[1][i]));
  }
  sort(ALL(ans));
  cout << ans[0] + ans[1] << endl;
  return 0;
}
