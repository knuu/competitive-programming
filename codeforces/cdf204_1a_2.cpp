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
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, cnt = 0, sum = 0;

  cin >> N;
  REP(i, 2 * N) {
    string a;
    cin >> a;
    int num = 0;
    REP(j, a.size()) {
      if (a[j] == '.') {
	REP(k, 3) {
	  num = 10 * num + (int)(a[j+k+1] - '0');
	}
      }
    }
    sum += num;
    if (!num) cnt++;
  }

  int ans = 2000000;
  if (cnt <= N) {
    FOR(i, N - cnt, N+1) {
      ans = min(ans, abs(i * 1000 - sum));
    }
  } else {
    REP(i, cnt + 1) {
      ans = min(ans, abs(i * 1000 - sum));
    }
  }
  printf("%.3lf\n", ans/1000.0);
  return 0;
}
