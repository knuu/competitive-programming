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
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, Q; cin >> N >> Q;
  vector<int> stops(N);
  vector<tuple<int, int, int>> times;
  REP(i, N) {
    int s, t, x; cin >> s >> t >> x;
    times.emplace_back(s-x, 0, i);
    times.emplace_back(t-x, -1, i);
    stops[i] = x;
  }
  REP(i, Q) {
    int d; cin >> d;
    times.emplace_back(d, 1, i);
  }
  sort(ALL(times));
  set<pair<int, int>> now;

  vector<int> ans(Q, -1);
  for (auto tu : times) {
    int t, k, i; tie(t, k, i) = tu;
    if (k == -1) {
      now.erase(make_pair(stops[i], i));
    } else if (k == 0) {
      now.insert(make_pair(stops[i], i));
    } else {
      if (now.size()) ans[i] = now.begin()->first;
    }
  }

  for (int v : ans) cout << v << endl;

  return 0;
}
