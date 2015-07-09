#include <iostream>
#include <algorithm>
 
using namespace std;
 
long long N, M, K;

bool check(long long x) {
  long long cnt = 0, now = M;
  for (long long i = 0; i < N; i++) {
    while (now > 0 && (i+1) * now > x) now--;
    cnt += now;
  }
  return cnt < K ? true : false;
}

int main() {
  cin >> N >> M >> K;
  long long low = 0, high = N*M;
  while (high - low > 1) {
    long long mid = (high + low) / 2;
    if (check(mid)) {
      low = mid;
    } else {
      high = mid;
    }
  }
  cout << high << endl;
  return 0;
}
