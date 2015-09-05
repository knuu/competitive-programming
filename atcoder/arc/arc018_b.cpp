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

bool is_triangle(ll x0, ll y0, ll x1, ll y1, ll x2, ll y2) {
  ll S = (y1 - y0) * (x2 - x0) - (x1 - x0) * (y2 - y0);
  return S != 0 && abs(S) % 2 == 0;
}

int main() {
  int N;
  ll points[128][2];

  cin >> N;
  REP(i, N) cin >> points[i][0] >> points[i][1];
  
  int ans = 0;
  REP(i, N) {
    FOR(j, i+1, N) {
      FOR(k, j+1, N) {
	if (is_triangle(points[i][0], points[i][1],
			points[j][0], points[j][1],
			points[k][0], points[k][1])) {
	  ans++;
	}
      }
    }
  }

  cout << ans << endl;  
  return 0;
}
