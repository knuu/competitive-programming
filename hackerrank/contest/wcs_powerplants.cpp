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

  int N, M; cin >> N >> M;
  vector<int> left(N, N), right(N, N);
  REP(i, M) {
    int s; cin >> s;
    left[s] = right[s] = 0;
  }
  REP(i, N-1) left[i+1] = min(left[i+1], left[i] + 1);
  for (int i = N-1; i > 0; i--) right[i-1] = min(right[i-1], right[i] + 1);
  int ans = 0;
  REP(i, N) ans = max(ans, min(left[i], right[i]));
  cout << ans << endl;
  return 0;
}
