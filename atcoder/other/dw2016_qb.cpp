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

  int N; cin >> N;
  Vi ans(N, 1e9);
  REP(i, N-1) {
    int k; cin >> k;
    ans[i] = min(ans[i], k);
    ans[i+1] = min(ans[i+1], k);
  }
  REP(i, N) cout << ans[i] << (i == N-1 ? '\n' : ' ');
  return 0;
}
