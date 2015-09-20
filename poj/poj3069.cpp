#include <iostream>
#include <algorithm>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (1) {
    int N, R, X[1024];
    cin >> R >> N;
    if (N == -1 && R == -1) break;
    REP(i, N) cin >> X[i];
    sort(X, X+N);
    int ans = 0;
    REP(i, N) {
      int now = i+1;
      ans++;
      while (now < N && X[now] <= X[i] + R) now++;
      int end = X[now-1] + R;
      while (now < N && X[now] <= end) now++;
      i = now-1;
    }    
    cout << ans << endl;
  }
  return 0;
}
