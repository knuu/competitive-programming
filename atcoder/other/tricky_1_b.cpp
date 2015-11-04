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
  int tests;
  scanf("%d", &tests);
  REP(test, tests) {
    ll A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);
    long double a = A, b = B, c = C;
    if (a == 0) {
      if (b != 0) {
	printf("1 %.16Lf\n", - 1.0 * c / b);
      } else if (c == 0) {
	printf("3\n");
      } else {
	printf("0\n");
      }
    } else {
      long double D = b * b - 4 * a * c;
      if (abs(D) < 1e-9) {
	printf("1 %.16Lf\n", - b / (2.0 * a));
      } else if (D < 0) {
	printf("0\n");
      } else {
	long double x1 = (- b - sqrt(D)) / (2.0 * a), x2 = (- b + sqrt(D)) / (2.0 * a);
	if (x1 > x2) swap(x1, x2);
	printf("2 %.16Lf %.16Lf\n", x1, x2);
      }
    }
  }
  return 0;
}
