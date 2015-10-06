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
  int x, y;
  scanf("%d %d", &x, &y);
  if (y > x) {
    printf("-1\n");
    return 0;
  }
  

  int left = 1, right = 1000000000;
  double top = (x + y) / 2.0;
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    if (top / mid >= y) {
      left = mid;
    } else {
      right = mid;
    }
  }
  printf("%.10lf\n", top / left);
  
  return 0;
}
