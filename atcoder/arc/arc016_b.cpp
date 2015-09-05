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
  int N;
  string music[128];

  cin >> N;
  REP(i, N) cin >> music[i];

  int ans = 0;
  REP(i, N) REP(j, 9) ans += (music[i][j] == 'x' || (music[i][j] == 'o' && (i == 0 || music[i-1][j] != 'o')));

  cout << ans << endl;
  return 0;
}
