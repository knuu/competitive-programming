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
  vector<pair<int, int>> water(N);

  REP(i, N) {
    int w, p; cin >> w >> p;
    water[i] = make_pair(p, w);
  }
  sort(ALL(water));
  double s = 0.0, w = 0.0;
  REP(i, K) {
    s += water[N-i-1].second * water[N-i-1].first / 100.0;
    w += water[N-i-1].second;
  }
  cout << setprecision(20) << s * 100 / w << endl;
  return 0;
}
