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

int A[300][300];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  REP(i, N) REP(j, M) {
    cin >> A[i][j];
    A[i][j]--;
  }
  int ans = N;
  vector<bool> can_use(M, true);

  while (any_of(ALL(can_use), [](bool x) { return x; })) {
    vector<int> cnt(M, 0);
    REP(i, N) {
      REP(j, M) {
        if (can_use[A[i][j]]) {
          cnt[A[i][j]]++;
          break;
        }
      }
    }

    int c_max = *max_element(ALL(cnt));
    ans = min(ans, c_max);
    REP(i, M) if (cnt[i] == c_max) can_use[i] = false;
    //REP(i, M) cout << cnt[i] << (i == M - 1 ? '\n' : ' ');
    //cout << c_max << endl;
    //REP(i, M) cout << can_use[i] << (i == M - 1 ? '\n' : ' ');
  }
  cout << ans << endl;

  return 0;
}
