#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int prime[1000010];
int dp[1000010];

int main() {
  fill(prime, prime+1000010, 1);

  for (int i = 2; i <= sqrt(1000000)+1; i++) {
    if (prime[i]) {
      for (int j = 2*i; j <= 1000000; j+=i) {
	prime[j] = 0;
      }
    }
  }
  prime[0] = prime[1] = 0;

  while (1) {
    int N, X;
    cin >> N >> X;
    if (N == 0 && X == 0) break;
    int price[40];
    for (int i = 0; i < N; i++) cin >> price[i];

    fill(dp, dp+1000010, 0);
    dp[0] = 1;
    for (int i = 0; i < X; i++) {
      if (!dp[i]) continue;
      for (int j = 0; j < N; j++) {
	if (i + price[j] <= X) dp[i+price[j]] = 1;
      }
    }

    bool flag = true;
    for (int i = X; i > 0; i--) {
      if (dp[i] && prime[i]) {
	cout << i << endl;
	flag = false;
	break;
      }
    }
    if (flag) cout << "NA" << endl;
  }
  return 0;
}
