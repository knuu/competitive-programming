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

vector<int> edge[100010];

int dfs(int v) {
  if (edge[v].size() == 0) return 0;
  vector<int> cand;
  for (int c : edge[v]) {
    cand.push_back(dfs(c));
  }
  sort(ALL(cand));
  int ans = 0;
  REP(i, edge[v].size()) {
    ans = max(ans, (int)edge[v].size() + cand[i] - i);
  }
  return ans;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  REP(i, N-1) {
    int c; cin >> c; c--;
    edge[c].push_back(i+1);
  }

  cout << dfs(0) << endl;
  return 0;
}
