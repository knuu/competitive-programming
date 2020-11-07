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

  int N; cin >> N;
  vector<set<int>> edges(N);
  REP(i, N-1) {
    int a, b; cin >> a >> b; a--, b--;
    edges[a].insert(b);
    edges[b].insert(a);
  }
  queue<int> degs;
  REP(i, N) {
    if (edges[i].size() == 1) degs.emplace(i);
  }

  vector<int> C(N); REP(i, N) cin >> C[i];
  sort(ALL(C));
  vector<int> ans(N, 0);

  int now = 0;

  while (degs.size() > 0) {
    int idx = degs.front(); degs.pop();
    //cout << idx << endl;
    ans[idx] = C[now++];
    if (edges[idx].size() > 0) {
      int nei = *edges[idx].begin();
      edges[nei].erase(idx);
      if (edges[nei].size() == 1) degs.emplace(nei);
    }
  }

  cout << accumulate(ALL(C), 0) - C.back() << endl;
  REP(i, N) cout << ans[i] << (i == N - 1 ? '\n' : ' ');
  return 0;
}
