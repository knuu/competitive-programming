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

  int N, K; cin >> N >> K;
  vector<int> a(N);

  for (int i = 0; i < N; i++) cin >> a[i];

  ll left = -1, right = 2*(int)1e9;
  while (left + 1 < right) {
    ll mid = (left + right) >> 1;
    vector<int> dp(N, 1);
    bool ok = false;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < i; j++) {
	if (abs(a[i] - a[j]) <= mid * (ll)(i - j)) {
	  dp[i] = max(dp[i], dp[j] + 1);
	}
      }
      if (N - dp[i] <= K) ok = true;
    }
    (ok ? right : left) = mid;
  }
  cout << right << endl;
  return 0;
}
