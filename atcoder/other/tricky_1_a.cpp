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

int main() {

  int test;
  scanf("%d", &test);
  REP(t, test) {
    ll A, B;
    scanf("%lld %lld", &A, &B);
    if (A == -9223372036854775808LL && B == -1) {
      printf("9223372036854775808\n");
    } else {
      printf("%lld\n", A / B);
    }
  }

  return 0;
}
