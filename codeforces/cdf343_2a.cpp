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
  vector<string> cake(N);
  REP(i, N) cin >> cake[i];
  int ans = 0;
  REP(i, N) {
    int cnt1 = 0, cnt2 = 0;
    REP(j, N) {
      if (cake[i][j] == 'C') cnt1++;
      if (cake[j][i] == 'C') cnt2++;
    }
    ans += cnt1 * (cnt1 - 1) / 2 + cnt2 * (cnt2 - 1) / 2;

  }
  cout << ans << endl;
  return 0;
}
