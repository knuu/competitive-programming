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
  vector<pair<int, int>> circles(N);
  REP(i, N) {
    int x, r; cin >> x >> r;
    circles[i] = make_pair(x-r, x+r);
  }
  sort(ALL(circles));
  vector<int> lis;
  for (int i = N - 1; i >= 0; i--) {
    int v = circles[i].second;
    int idx = lower_bound(ALL(lis), v) - lis.begin();
    if (idx == (int)lis.size()) {
      lis.push_back(v);
    } else {
      lis[idx] = v;
    }
  }
  cout << lis.size() << endl;
  return 0;
}
