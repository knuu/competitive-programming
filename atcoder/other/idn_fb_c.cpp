#include <iostream>
#include <cmath>

using namespace std;

int pal[5010][5010];
int c[5010];
int dp[5010];


int main(){
  int n;
  char s[5010];
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> c[i];
  
  for (int k = 0; k < n; k++) {
    for (int i = k, j = k; i >= 0 && j < n; i--, j++) {
      if (s[i] != s[j]) break;
      pal[i][j] = true;
    }
    for (int i = k, j = k+1; i >= 0 && j < n; i--, j++) {
      if (s[i] != s[j]) break;
      pal[i][j] = true;
    }
  }

  for (int i = 0; i < n+1; i++) dp[i] = n * (int)pow(10, 5);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i+1; j++) {
      if (pal[j][i]) dp[i+1] = min(dp[i+1], dp[j] + c[i-j]);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
