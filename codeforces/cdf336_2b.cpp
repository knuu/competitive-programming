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

ll B_count[200010][2];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string a, b; cin >> a >> b;
  int La = a.size(), Lb = b.size();
  REP(i, Lb) B_count[i+1][b[i] - '0']++;
  REP(i, Lb) REP(j, 2) B_count[i+1][j] += B_count[i][j];
  // REP(i, Lb) REP(j, 2) cout << B_count[i+1][j] << endl;

  ll ans = 0;
  REP(i, La) {
    ans += B_count[i + Lb - La + 1][a[i] == '0'] - B_count[i][a[i] == '0'];
  }
  cout << ans << endl;
  return 0;
}
