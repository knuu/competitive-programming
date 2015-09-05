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
  int N, A[1024], ans = 0;

  scanf("%d", &N);
  REP(i, N) scanf("%d", A+i);

  while (true) {
    auto it = max_element(A+1, A+N);
    if (A[0] > *it) break;

    A[0]++;
    A[it-A]--;
    ans++;
  }

  printf("%d\n", ans);
  return 0;
}
