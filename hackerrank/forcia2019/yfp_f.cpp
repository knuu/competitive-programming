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

int N;
vector<vector<ll>> edge;
vector<ll> num_child, sum_dist;
vector<ll> dp;

pair<ll, ll> dfs(int v, int p) {
  ll nc = 0, sd = 0;
  for (int c : edge[v]) {
    if (c == p) continue;
    ll ncc, sdd; tie(ncc, sdd) = dfs(c, v);
    nc += ncc;
    sd += sdd;
  }
  num_child[v] = nc;
  sum_dist[v] = sd;
  return make_pair(nc + 1, sd + nc + 1);
}

void dfs2(int v, int p, ll n_other, ll dist_other) {
  dp[v] = sum_dist[v] + dist_other + n_other;
  for (int c : edge[v]) {
    if (c == p) continue;
    dfs2(c, v, N - num_child[c] - 1, dp[v] - (sum_dist[c] + num_child[c] + 1));
  }
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N;
  edge.resize(N);
  num_child.resize(N);
  sum_dist.resize(N);
  dp.resize(N);
  REP(i, N - 1) {
    int p; cin >> p;
    edge[i + 1].emplace_back(p);
    edge[p].emplace_back(i + 1);
  }
  dfs(0, -1);
  dfs2(0, -1, 0, 0);
  for (ll x : dp) cout << x << endl;



  return 0;
}
