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
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<int> A(N), B(N);
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];

  int ans = 0;
  REP(i, 29) {
    vector<int> mod_A(N), mod_B(N);
    REP(j, N) {
      mod_A[j] = A[j] & ((1 << (i + 1)) - 1);
    }
    REP(j, N) {
      mod_B[j] = B[j] & ((1 << (i + 1)) - 1);
    }
    sort(ALL(mod_B));

    int cnt = 0;
    for (int a : mod_A) {
      cnt += (lower_bound(ALL(mod_B), (1 << (i + 1)) - a) - mod_B.begin()) - (lower_bound(ALL(mod_B), (1 << i) - a) - mod_B.begin());
      cnt += (lower_bound(ALL(mod_B), (1 << (i + 2)) - a) - mod_B.begin()) - (lower_bound(ALL(mod_B), 3 * (1 << i) - a) - mod_B.begin());
    }
    if (cnt & 1) ans |= (1 << i);
  }
  cout << ans << endl;
  return 0;
}
