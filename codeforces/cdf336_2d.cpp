#include <bits/stdc++.h>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int dp[512][512], c[512];
const int INF = 500;

int main() {
  int N; cin >> N;
  REP(i, N) cin >> c[i];
  
  REP(w, N) {
    for (int left = 0; left + w <= N; left++) {
      int right = left + w;
      dp[left][right] = INF;
      for (int mid = left; mid <= right; mid++) {
	if (c[left] == c[mid]) {
	  dp[left][right] = min(dp[left][right], max(1, dp[left+1][mid-1]) + dp[mid+1][right]);
	} else {
	  dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid+1][right]);
	}
      }
    }
  }
  cout << dp[0][N-1] << endl;  
  return 0;
}
