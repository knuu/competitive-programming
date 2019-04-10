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
  vector<ll> num(N);
  REP(i, N) cin >> num[i];
  ll sum = accumulate(num.begin(), num.end(), 0LL);
  if (sum % 2LL == 0) {
    cout << sum << endl;
  } else {
    ll ans = 0;
    REP(i, N) {
      if ((sum - num[i]) % 2LL == 0) {
	ans = max(ans, sum - num[i]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
