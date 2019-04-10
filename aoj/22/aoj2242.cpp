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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

tuple<int, int, string> era[1024];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (true) {
    int N, Q;
    cin >> N >> Q;
    if (N == 0 && Q == 0) break;
    REP(i, N) {
      string en;
      int eby, wy;
      cin >> en >> eby >> wy;
      era[i] = make_tuple(wy - eby + 1, wy, en);
    }

    REP(_, Q) {
      int q;
      cin >> q;
      bool flag = true;
      REP(i, N) {
	int es, ee;
	string en;
	tie(es, ee, en) = era[i];
	if (es <= q && q <= ee) {
	  cout << en << ' ' << q - es + 1 << endl;
	  flag = false;
	  break;
	}
      }
      if (flag) {
	cout << "Unknown" << endl;
      }
    }
  }			    
  return 0;
}
