#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

int N, Q;
int S[100010];

int main() {
  int ans = 0;

  scanf("%d", &N);
  REP(i, N) scanf("%d", S+i);

  scanf("%d", &Q);
  REP(i, Q) {
    int t;
    scanf("%d", &t);
    auto it = lower_bound(S, S+N, t);
    ans += (it != S+N && t == *it);
  }

  printf("%d\n", ans);
  return 0;
}
