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
  vector<string> tags(N); REP(i, N) cin >> tags[i];
  vector<string> ans(N); ans[N - 1] = tags[N - 1];
  for (int i = N - 2; i >= 0; i--) {
    bool flag = true;
    for (int j = 0; j < min<int>(tags[i].size(), ans[i + 1].size()); j++) {
      if (tags[i][j] > ans[i + 1][j]) {
        ans[i] = tags[i].substr(0, j);
        flag = false;
        break;
      } else if (tags[i][j] < ans[i + 1][j]) {
        ans[i] = tags[i];
        flag = false;
        break;
      }
    }
    if (flag) {
      ans[i] = tags[i].substr(0, min<int>(tags[i].size(), ans[i + 1].size()));
    }
  }

  for (string s : ans) cout << s << endl;

  return 0;
}
