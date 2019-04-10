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
  string S; cin >> S;
  int L = S.size();

  vector<vector<int>> dp(L+1, vector<int>(L+1, 0));
  // [left, right)
  FOR(w, 3, L+1) REP(left, L-w+1) {
    int right = left + w;
    for (int mid = left + 1; mid < right; mid++) {
      dp[left][right] = max(dp[left][right], dp[left][mid] + dp[mid][right]);
    }
    if (S[left] == 'i' and S[right-1] == 'i') {
      for (int mid = left + 1; mid < right - 1; mid++) {
        if (S[mid] == 'w' and (dp[left + 1][mid] + dp[mid + 1][right - 1]) * 3 == right - left - 3) {
          dp[left][right] = (right - left) / 3;
          break;
        }
      }
    }
  }
  cout << dp[0][L] << endl;
  return 0;
}
