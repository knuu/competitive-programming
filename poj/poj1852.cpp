#include <iostream>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  REP(t, T) {
    int N, L;
    cin >> L >> N;
    int minT = 0, maxT = 0;
    REP(i, N) {
      int x;
      cin >> x;
      minT = max(minT, min(L-x, x));
      maxT = max(maxT, max(L-x, x));
    }
    cout << minT << ' ' << maxT << endl;
  }
  return 0;
}
