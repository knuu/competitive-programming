#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

#define eps 1e-4

int N, K;
double L[10010];

double solve() {
  double low = 0.0, high = 1e9;
  while (low + eps < high) {
    double mid = (low + high) / 2.0;
    int cancut = 0;
    REP(j, N) cancut += (int)(L[j] / mid);
    if (cancut >= K) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return high;
}    

int main() {
  scanf("%d %d", &N, &K);
  REP(i, N) scanf("%lf", L+i);

  printf("%.2f\n", floor(solve() * 100) / 100);
  return 0;
}
