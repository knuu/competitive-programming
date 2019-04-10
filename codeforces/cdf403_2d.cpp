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
  vector<vector<string>> teams(N, vector<string>(2));
  REP(i, N) REP(j, 2) cin >> teams[i][j];
  vector<int> rules(N, 0);
  map<string, vector<int>> short_name;

  set<string> names_set;

  REP(i, N) short_name[teams[i][0].substr(0, 3)].emplace_back(i);
  for (auto p : short_name) {
    if ((int)p.second.size() > 1) {
      for (int i : p.second) {
        rules[i] = 1;
        string name = teams[i][0].substr(0, 2);
        name.push_back(teams[i][1][0]);
        names_set.insert(name);
      }
    }
  }

  set<pair<int, string>> res;
  for (auto p : short_name) {
    if ((int)p.second.size() == 1) {
      res.emplace(p.second[0], p.first);
    }
  }

  while (true) {
    vector<pair<int, string>> lazy;
    for (auto p : res) {
      int idx; string sname; tie(idx, sname) = p;
      if (names_set.find(sname) != names_set.end()) {
        rules[idx] = 1;
        string name = teams[idx][0].substr(0, 2);
        name.push_back(teams[idx][1][0]);
        names_set.insert(name);
        lazy.emplace_back(p);
      }
    }
    if ((int)lazy.size() == 0) {
      for (auto p : res) names_set.emplace(p.second);
      break;
    } else {
      for (auto p : lazy) res.erase(p);
    }
  }

  if ((int)names_set.size() != N) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    REP(i, N) {
      if (rules[i] == 0) {
        cout << teams[i][0].substr(0, 3) << endl;
      } else {
        string name = teams[i][0].substr(0, 2);
        name.push_back(teams[i][1][0]);
        cout << name << endl;
      }
    }
  }
  return 0;
}
