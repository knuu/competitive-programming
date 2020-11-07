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
double dp[601][2];
vector<vector<int>> edge, rev_edge;

double rec(int v, bool flag) {
  if (v == N - 1) {
    cout << v << ' ' << flag << ' ' << 1 << ' ' << 0.0 << endl;
    return 0.0;
  }
  if (dp[v][flag] >= 0.0) {
    cout << v << ' ' << flag << ' ' << 2 << ' ' << dp[v][flag] << endl;
    return dp[v][flag];
  }

  double ret = 0;
  if (flag) {
    for (int c : edge[v]) {
      ret += rec(c, flag);
    }
    ret = 1 + ret / edge[v].size();
  } else if (edge[v].size() == 1) {
    ret = 1e9;
  } else {
    double max_val = 0.0;
    for (int c : edge[v]) {
      double val = rec(c, 1);
      max_val = max(val, max_val);
      ret += val;
    }
    ret = 1 + (ret - max_val) / (edge.size() - 1);
  }
  dp[v][flag] = ret;
  cout << v << ' ' << flag << ' ' << 3 << ' ' << dp[v][flag] << endl;

  return ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int M; cin >> N >> M;
  edge.resize(N);
  rev_edge.resize(N);

  REP(i, M) {
    int s, t; cin >> s >> t; s--, t--;
    edge[s].emplace_back(t);
    rev_edge[t].emplace_back(s);
  }
  REP(i, N) REP(j, 2) dp[i][j] = -1.0;

  rec(0, 0);
  rec(0, 1);


  cout << (rec(0, 0) < 1e9 ? rec(0, 0) : rec(0, 1)) << endl;
  return 0;
}
