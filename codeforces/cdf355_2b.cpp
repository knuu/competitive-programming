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

  ll N, H, K; cin >> N >> H >> K;
  vector<ll> potato(N); REP(i, N) cin >> potato[i];
  ll ans = 0, now_h = 0;
  REP(i, N) {
    if (now_h + potato[i] > H) {
      ll x = (ll)ceil(1.0 * (potato[i] + now_h - H) / K);
      ans += x;
      now_h = max<ll>(0, now_h - x * K);
      //cout << i << ':' << now_h << endl;;
    }
    assert(now_h + potato[i] <= H);
    while (i < N and now_h + potato[i] <= H) {
      now_h += potato[i];
      //cout << i << ':' << now_h << endl;
      i++;
    }
    i--;
    assert(now_h <= H);
    //cout << ans << ' ' << now_h << endl;
  }
  cout << ans + (ll)ceil(1.0 * now_h / K) << endl;
  return 0;
}
