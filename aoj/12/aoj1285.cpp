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
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (1) {
    int N, W; cin >> N >> W;
    if (N == 0 and W == 0) break;
    vector<int> value(N);
    REP(i, N) cin >> value[i];
    int max_v = *max_element(ALL(value));
    int cnt_len = max_v / W + 1;
    vector<int> counter(cnt_len, 0);
    for (int v : value) {
      REP(i, cnt_len) {
        if (v < (i+1) * W) {
          counter[i]++;
          break;
        }
      }
    }
    int M = *max_element(ALL(counter));
    double ans = 0.0;
    REP(i, cnt_len) ans += 1.0  * (cnt_len-1 - i) /  (cnt_len-1) * counter[i] / M;
    cout << setprecision(20) << ans + 0.01 << endl;
  }
  return 0;
}
