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

map<pair<int, map<int, int>>, int> memo;
int N;

int dfs(int res, map<int, int> mp) {
  if (res == 0) {
    int ret = 0;
    for (auto p : mp) {
      int d = p.first * 1000 / N;
      //cout << p.first << ' ' << d << ' ' << (d % 10 >= 5 ? true : false) << endl;
      if (d % 10 >= 5) {
        ret += (d / 10 + 1) * p.second;
      } else {
        ret += d / 10 * p.second;
      }
    }
    //cout << ret << endl;
    //cout << endl;
    return ret;
  }
  pair<int, map<int, int>> state = make_pair(res, mp);
  if (memo.find(state) != memo.end()) {
    return memo[state];
  }
  int ans = 0;
  for (auto p : mp) {
    map<int, int> next_mp = mp;
    next_mp[p.first + 1]++;
    next_mp[p.first]--;
    if (next_mp[p.first] == 0) {
      next_mp.erase(p.first);
    }
    ans = max(ans, dfs(res - 1, next_mp));
  }
  map<int, int> next_mp = mp;
  next_mp[1]++;
  ans = max(ans, dfs(res - 1, next_mp));
  return memo[state] = ans;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  REP(testcase, T) {
    int L; cin >> N >> L;
    map<int, int> mp;
    int res = N;
    REP(i, L) {
      int l; cin >> l;
      res -= l;
      mp[l]++;
    }

    memo.clear();
    cout << "Case #" << testcase + 1 << ": " << dfs(res, mp) << endl;
  }

  return 0;
}
