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
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

int main() {
  int H, W, choco[128][128];

  scanf("%d %d", &H, &W);
  REP(i, H+1) fill(choco[i], choco[i] + W + 1, 0);
  REP(i, H) REP(j, W) {
    int n;
    scanf("%d", &n);
    choco[i+1][j+1] += ((i+j) % 2 ? -1 : 1) * n;
  }

  REP(i, H+1) REP(j, W) choco[i][j+1] += choco[i][j];
  REP(i, H) REP(j, W+1) choco[i+1][j] += choco[i][j];

  //  REP(i, H+1) REP(j, W+1) cout << choco[i][j] << (j == W ? '\n' : ' ');
  int ans = 0;
  REP(sh, H) REP(sw, W) {
    FOR(eh, sh, H) FOR(ew, sw, W) {
      if (choco[eh+1][ew+1] - choco[sh][ew+1] - choco[eh+1][sw] + choco[sh][sw] == 0) {
	ans = max(ans, (eh-sh+1) * (ew-sw+1));
      }
    }
  }

  cout << ans << endl;
  return 0;
}
