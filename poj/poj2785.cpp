#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int list[4][4096];
int sum[2][16000001];

int main() {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  REP(i, N) REP(j, 4) cin >> list[j][i];

  REP(i, N) REP(j, N) {
    sum[0][i*N+j] = list[0][i] + list[1][j];
    sum[1][i*N+j] = list[2][i] + list[3][j];
  }
  sort(sum[1], sum[1]+N*N);

  long long ans = 0;
  REP(i, N*N) {
    ans += upper_bound(sum[1], sum[1]+N*N, -sum[0][i]) - lower_bound(sum[1], sum[1]+N*N, -sum[0][i]);
  }

  cout << ans << endl;	   
  return 0;
}
