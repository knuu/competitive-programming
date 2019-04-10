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

set<int> calc_set(int s) {
  set<int> ret;
  for (int k = 0, i = (s / 50) % 475; k < 25; k++) {
    i = (i * 96 + 42) % 475;
    ret.insert(i + 26);
  }
  return ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int p, x, y; cin >> p >> x >> y;
  for (int i = x; i >= y; i -= 50) {
    set<int> ranks = calc_set(i);
    if (ranks.find(p) != ranks.end()) {
      cout << 0 << endl;
      return 0;
    }
  }

  for (int i = 1; ; i++) {
    set<int> ranks = calc_set(x + i * 50);
    if (ranks.find(p) != ranks.end()) {
      cout << (i + 1) / 2 << endl;
      return 0;
    }
  }


  return 0;
}
