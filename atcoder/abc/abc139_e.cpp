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
const int INF = 1e8;

int dfs(int v, vector<vector<int>>& edges, vector<int>& dp, vector<bool>& used) {
  if (dp[v] > 0) {
    return dp[v];
  }
  if (used[v]) {
    return INF;
  }
  used[v] = true;
  int ret = 0;
  for (int c : edges[v]) {
    ret = max(ret, dfs(c, edges, dp, used));
  }
  return dp[v] = ret + 1;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  map<pair<int, int>, int> mp;
  int cnt = 0;
  REP(i, N) REP(j, N) {
    if (i < j) {
      mp[make_pair(i, j)] = mp[make_pair(j, i)] = cnt;
      //cout << '(' << i << ',' << j << ")=" << cnt << endl;
      cnt++;
    }
  }

  vector<vector<int>> edges(cnt);
  REP(i, N) {
    vector<int> A(N-1); REP(j, N-1) cin >> A[j], A[j]--;
    REP(j, N-2) {
      int from = mp[make_pair(i, A[j])], to = mp[make_pair(i, A[j+1])];
      //cout << from << "->" << to << endl;
      edges[from].push_back(to);
    }
  }
  vector<int> dp(cnt, 0);
  vector<bool> used(cnt, false);
  int ans = 0;
  REP(i, cnt) {
    ans = max(ans, dfs(i, edges, dp, used));
  }
  cout << (ans >= INF ? -1 : ans) << endl;
  return 0;
}
