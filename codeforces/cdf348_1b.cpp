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

int main() {
  int N, Q; scanf("%d %d", &N, &Q);
  int even = 0, odd = 0;
  REP(i, Q) {
    int t; scanf("%d", &t);
    if (t == 1) {
      int x; scanf("%d", &x);
      even = (even + x + N) % N;
      odd = (odd + x + N) % N;
    } else {
      if (even % 2 == 0) {
        even = (even + 1 + N) % N;
        odd = (odd - 1 + N) % N;
      } else {
        even = (even - 1 + N) % N;
        odd = (odd + 1 + N) % N;
      }
    }
  }
  vector<int> ans(N);
  for (int i = 0; i < N; i += 2) ans[(i+even)%N] = i+1;
  for (int i = 1; i < N; i += 2) ans[(i+odd)%N] = i+1;
  REP(i, N) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");



  return 0;
}
