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
  int N, M; cin >> N >> M;
  vector<vector<int>> start_pos(N), end_pos(N);
  vector<ll> costs(M);
  REP(i, M) {
    int l, r; ll c; cin >> l >> r >> c; l--, r--;
    start_pos[l].emplace_back(i);
    end_pos[r].emplace_back(i);
    costs[i] = c;
  }

  vector<ll> dist(N);
  dist[0] = 0;
  set<pair<ll, int>> intervals;

  vector<pair<ll, int>> memo(M);
  for (int idx : start_pos[0]) {
    intervals.emplace(costs[idx], idx);
    memo[idx] = make_pair(costs[idx], idx);
  }

  FOR(i, 1, N) {
    if (intervals.empty()) {
      cout << -1 << endl;
      return 0;
    }

    dist[i] = intervals.begin()->first;
    for (int idx : end_pos[i]) {
      intervals.erase(memo[idx]);
    }
    for (int idx : start_pos[i]) {
      intervals.emplace(dist[i] + costs[idx], idx);
      memo[idx] = make_pair(dist[i] + costs[idx], idx);
    }
  }

  cout << dist[N-1] << endl;

  return 0;
}
