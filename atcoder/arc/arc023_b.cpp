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

int room[1024][1024];

int main() {
  int R, C, D;
  cin >> R >> C >> D;
  REP(i, R) REP(j, C) scanf("%d", &room[i][j]);

  int ans = 0;
  REP(r, R) {
    REP(c, C) {
      if (r + c <= D && (r + c) % 2 == D % 2) {
	ans = max(ans, room[r][c]);
      }
    }
  }

  cout << ans << endl;  
  return 0;
}
