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

const int dr[9] = {-1, -1, -1, 0, 1, 1, 1, 0, 0};
const int dc[9] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int H, W, N; cin >> H >> W >> N;
  vector<P> black(N);
  set<P> black_set;
  REP(i, N) {
    int a, b; cin >> a >> b; a--, b--;
    black[i] = P(a, b);
    black_set.insert(P(a, b));
  }

  vector<ll> cnt(10, 0LL);
  set<P> done;
  cnt[0] = (ll)(H-2) * (ll)(W-2);

  for (P p : black) {
    int r = p.first, c = p.second;
    REP(i, 9) {
      int cr = r+dr[i], cc = c+dc[i];
      if (cr <= 0 or cr >= H-1 or cc <= 0 or cc >= W-1 or done.find(P(cr, cc)) != done.end()) continue;
      done.insert(P(cr, cc));
      int r_cnt = 0;
      REP(i, 9) {
        int nr = cr + dr[i], nc = cc + dc[i];
        if (black_set.find(P(nr, nc)) != black_set.end()) r_cnt++;
      }
      cnt[r_cnt]++;
      cnt[0]--;
    }
  }
  for (ll c : cnt) cout << c << endl;

  return 0;
}
