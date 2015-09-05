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
  int N, K;
  map<int, int> rank;

  scanf("%d %d", &N, &K);
  REP(i, K) {
    int x;
    scanf("%d", &x);
    rank[-x] = i+1;
  }

  auto it = rank.begin();
  cout << it->second << endl;
  FOR(i, K, N) {
    int x;
    scanf("%d", &x);
    if (x < -(it->first)) {
      rank[-x] = i+1;
      it++;
    }
    printf("%d\n", it->second);
  }    

  return 0;
}
