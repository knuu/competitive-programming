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
  int N; scanf("%d", &N);
  vector<double> max_p(N), min_p(N);
  REP(i, N) scanf("%lf", &max_p[i]);
  REP(i, N) scanf("%lf", &min_p[i]);
  REP(i, N-1) max_p[i+1] += max_p[i], min_p[i+1] += min_p[i];
  vector<vector<double>> ans(2);

  double pa = 0.0, pb = 0.0;
  REP(i, N) {
    double beta = max_p[i], alpha = beta + min_p[i];
    double D = max(0.0, alpha * alpha - 4.0 * beta);
    double t1 = (alpha + sqrt(D)) / 2.0;
    double t2 = (alpha - sqrt(D)) / 2.0;
    ans[0].push_back(t1 - pa);
    ans[1].push_back(t2 - pb);
    pa = t1, pb = t2;
  }
  REP(i, 2) {
    REP(j, N) {
      if (j) printf(" ");
      printf("%.20lf", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
