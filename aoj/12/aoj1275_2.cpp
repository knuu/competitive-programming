#include <bits/stdc++.h>

using namespace std;

int f(int n, int k) { return n == 1 ? 0 : (f(n-1, k) + k) % n; }

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (1) {
    int N, K, M; cin >> N >> K >> M;
    if (N == 0 and K == 0 and M == 0) break;
    cout << (f(N-1, K) + M) % N + 1 << endl;
  }
  return 0;
}
