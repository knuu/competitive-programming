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

ll A, B;

inline ll s(ll i) { return A + (i - 1) * B; }

int main() {
  int a, b, N;
  scanf("%d %d %d", &a, &b, &N);
  A = (ll)a, B = (ll)b;

  REP(i, N) {
    ll L, T, M;
    int l, t, m;
    scanf("%d %d %d", &l, &t, &m);
    L = (ll)l, T = (ll)t, M = (ll)m;
    if (s(L) > T) {
      printf("-1\n");
      continue;
    }
    ll left = L, right = L + T;
    while (left + 1 < right) {
      // cout << left << ' ' << right << endl;
      ll mid = (left + right) / 2;
      ll sum = (mid - L + 1) * (s(L) + s(mid)) / 2LL;
      if (s(mid) <= T && sum <= T * M) {
	left = mid;
      } else {
	right = mid;
      }
    }
    printf("%d\n", (int)left);
  }
  return 0;
}
