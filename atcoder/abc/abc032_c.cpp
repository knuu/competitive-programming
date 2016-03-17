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
  ll N, K; cin >> N >> K;
  vector<ll> s(N);
  REP(i, N) cin >> s[i];
  if (find(s.begin(), s.end(), 0) != s.end()) {
    cout << N << endl;
    return 0;
  } else if (K == 0) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  ll now = 1LL;
  int l = 0, r = 0;
  while (l < N) {
    while (r < N and s[r] * now <= K) now *= s[r++];
    ans = max(ans, r - l);
    if (r == N) break;
    now *= s[r++];
    while (l < N and now > K) now /= s[l++];
  }
  cout << ans << endl;
  return 0;
}
