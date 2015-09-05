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

int bids[100010];

int main() {
  int N;
  scanf("%d", &N);
  REP(i, N) scanf("%d", &bids[i]);

  REP(i, N) {
    while (bids[i] % 2 == 0) bids[i] /= 2;
    while (bids[i] % 3 == 0) bids[i] /= 3;
  }

  int a = bids[0];
  int flag = true;
  REP(i, N) {
    if (a != bids[i]) {
      flag = false;
      break;
    }
  }

  printf(flag ? "Yes\n" : "No\n");

  return 0;
}
