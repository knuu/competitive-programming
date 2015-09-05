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
  int C, pack[128][3];
  cin >> C;
  REP(i, C) REP(j, 3) cin >> pack[i][j];
  REP(i, C) sort(pack[i], pack[i] + 3);

  int *m = pack[0];
  REP(i, C) REP(j, 3) m[j] = max(m[j], pack[i][j]);

  cout << m[0] * m[1] * m[2] << endl;
    
  return 0;
}
