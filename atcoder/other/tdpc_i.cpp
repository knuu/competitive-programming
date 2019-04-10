#include <bits/stdc++.h>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int memo[301][301];
string S;

// [L, R)
int dp(int L, int R) {
  if (R - L <= 2) return 0;
  if (R - L == 3) return S.substr(L, 3) == "iwi";
  if (memo[L][R] != -1) return memo[L][R];

  if (S[L] == 'i' and S[R-1] == 'i') {
    for (int i = L+1; i < R-1; i++) {
      if (S[i] == 'w' and dp(L+1, i) * 3 == i - (L+1) and dp(i+1, R-1) * 3 == R-1 - (i+1)) {
        return memo[L][R] = (R - L) / 3;
      }
    }
  }
  int ret = 0;
  for (int i = L+1; i < R; i++) ret = max(ret, dp(L, i) + dp(i, R));
  return memo[L][R] = ret;
}

int main() {
  cin >> S;
  memset(memo, -1, sizeof(memo));
  cout << dp(0, S.size()) << endl;
  return 0;
}
