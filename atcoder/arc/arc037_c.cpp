#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
long long a[30010];
long long b[30010];

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++) cin >> b[i];
  sort(a, a+N);
  sort(b, b+N);
  long long low = 0, high = (long long)1e18;
  while (high - low > 1) {
    long mid = (high + low) / 2;
    int cnt = 0, now = N-1;
    for (int i = 0; i < N; i++) {
      while (now >= 0 && a[i] * b[now] > mid) now--;
      cnt += now + 1;
    }
    if (cnt < K) {
      low = mid;
    } else {
      high = mid;
    }
  }
  cout << high << endl;
  return 0;
}
