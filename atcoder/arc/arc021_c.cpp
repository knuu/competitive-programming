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

ll K, N;
ll A[100010], D[100010];

bool check(ll V) {
  ll cnt = 0;
  REP(i, N) {
    if (V + D[i] - A[i] > 0) {
      cnt +=(ll)floor(1.0 * (V + D[i] - A[i]) / D[i]);
    }
    if (cnt >= K) return true;
  }
  return false;
}

int main() {
  scanf("%lld %lld", &K, &N);
  REP(i, N) scanf("%lld %lld", A+i, D+i);

  ll left = 0, right = (ll)1e11;
  while (left + 1 < right) {
    ll mid = (left + right) / 2;
    if (check(mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }

  ll V = right, ans = 0, cnt = 0;
  REP(i, N) {
    if (V + D[i] - A[i] > 0) {
      ll c = (ll)floor(1.0 * (V + D[i] - A[i]) / D[i]);
      ans += c * A[i] + D[i] * (c * (c - 1) / 2);
      cnt += c;
    }
  }
  ans -= V * (cnt - K);
  printf("%lld\n", ans);
  return 0;
}
