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

  int T; cin >> T;
  REP(t, T) {
    int N, K; cin >> N >> K;
    vector<tuple<ll, ll, ll>> cakes(N);
    REP(i, N) {
      ll r, h; cin >> r >> h;
      cakes[i] = make_tuple(r, h, 2 * r * h);
    }
    sort(ALL(cakes));
    ll ans = 0;
    for (int i = N - 1; i >= K - 1; i--) {
      ll r, h, rh2; tie(r, h, rh2) = cakes[i];
      ll cand = r * r + rh2;
      vector<ll> tmp;
      REP(j, i) {
        ll r, h, rh2; tie(r, h, rh2) = cakes[j];
        tmp.emplace_back(-rh2);
      }
      sort(ALL(tmp));
      REP(i, K - 1) cand -= tmp[i];
      ans = max(ans, cand);
    }
    printf("Case #%d: %.020f\n", t + 1, ans * acos(-1));
  }


  return 0;
}
