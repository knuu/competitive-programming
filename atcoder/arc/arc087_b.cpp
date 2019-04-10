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
  string S; cin >> S;
  int L = S.size();
  int r, c; cin >> r >> c;
  vector<vector<int>> f_count(2);
  int d = 0, cnt = 0;
  for (auto s : S) {
    if (s == 'F') {
      cnt++;
    } else {
      f_count[d].emplace_back(cnt);
      cnt = 0;
      d ^= 1;
    }
  }
  f_count[d].emplace_back(cnt);

  int geta = 2 * L;
  if (abs(r) > geta or abs(c) > geta) {
    cout << "No" << endl;
    return 0;
  }
  vector<vector<bool>> dp(2, vector<bool>(2 * geta + 1, false));
  dp[0][geta] = dp[1][geta] = true;
  REP(i, 2) {
    REP(k, f_count[i].size()) {
      vector<bool> _dp(2 * geta + 1, false);
      int fc = f_count[i][k];
      for (int j = -geta; j <= geta; j++) {
        if (dp[i][j + geta]) {
          if (i == 0 and k == 0) {
            _dp[j + geta + fc] = true;
          } else {
            _dp[j + geta - fc] = _dp[j + geta + fc] = true;
          }
        }
      }
      dp[i] = _dp;
    }
  }

  cout << (dp[0][r + geta] and dp[1][c + geta] ? "Yes" : "No") << endl;

  return 0;
}
