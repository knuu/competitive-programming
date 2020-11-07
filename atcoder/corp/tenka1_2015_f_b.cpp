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

Vi edge[32];

int main() {
  int V, E, K;
  scanf("%d %d %d", &V, &E, &K);
  REP(i, E) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  int comb = (1 << K) - 1;
  while (comb < 1 << V) {
    bool used[32];
    fill (used, used + V, false);
    bool can_use = true;
    REP(i, V) {
      if (((comb >> (V-1-i)) & 1) == 0) continue;
      bool flag = true;
      for (auto adj : edge[i]) {
	if (used[adj]) {
	  flag = false;
	  break;
	}
      }
      if (flag == false) {
	can_use = false;
	break;
      } else {
	used[i] = true;
      }
    }
    if (can_use) {
      REP(i, V) {
	if ((comb >> (V-1-i)) & 1) {
	  cout << i << endl;
	}
      }
      break;
    }
    int x = comb & -comb, y = comb + x;
    comb = ((comb & ~y) / x >> 1) | y;

  }

  return 0;
}
