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

int counter[(1<<15)+1];

int main() {
  FOR(i, 1, 182) {
    counter[i*i]++;
    FOR(j, i, 182) {
      if (i*i+j*j > 1<<15) break;
      counter[i*i+j*j]++;
      FOR(k, j, 182) {
        if (i*i+j*j+k*k > 1<<15) break;
        counter[i*i+j*j+k*k]++;
        FOR(l, k, 182) {
          if (i*i+j*j+k*k+l*l > 1<<15) break;
          counter[i*i+j*j+k*k+l*l]++;
        }
      }
    }
  }

  while (1) {
    int n; scanf("%d", &n);
    if (not n) break;
    printf("%d\n", counter[n]);
  }
  return 0;
}
