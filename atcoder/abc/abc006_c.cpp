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
  int N, M;
  scanf("%d %d", &N, &M);

  int adult = max(3 * N - M, 0);
  int old = 4 * N - M - 2 * adult;
  int child = N - old - adult;
  old >= 0 ? printf("%d %d %d\n", adult, old, child) : printf("-1 -1 -1\n");

  return 0;
}
