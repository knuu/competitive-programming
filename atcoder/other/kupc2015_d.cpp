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

ll N;
ll A[100010], B[100010];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  REP(i, N) cin >> A[i];
  REP(i, N) cin >> B[i];

  ll need = 0, cnt = 0, ans = 0, max_B = 0;
  REP(i, N) {
    max_B = max(max_B, B[i]);
    ans = max(ans, need + max_B * (N - cnt));
    
    need += A[i]; cnt++;
    while (cnt < N && need < 0) {
      need += max_B;
      cnt++;
    }
    if (cnt == N) {
      if (need >= 0) ans = max(ans, need);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
