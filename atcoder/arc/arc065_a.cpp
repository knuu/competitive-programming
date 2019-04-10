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
  vector<string> cand = {"dream", "dreamer", "erase", "eraser"};
  string S; cin >> S;
  int L = S.size();
  vector<bool> dp(L+1, false);

  dp[0] = true;
  REP(i, L) {
    if (not dp[i]) continue;
    for (string s : cand) {
      bool flag = true;
      for (int j = 0; j < (int)s.size(); j++) {
        if (i + j >= L) {
          flag = false;
          break;
        }
        flag &= S[i+j] == s[j];
      }
      if (flag) dp[i+s.size()] = true;
    }
  }

  cout << (dp[L] ? "YES" : "NO") << endl;
  return 0;
}
