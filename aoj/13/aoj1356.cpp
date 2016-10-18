#include <bits/stdc++.h>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int main() {
  int N; cin >> N;
  vector<int> num(N);
  REP(i, N) cin >> num[i];

  set<int> num_set;
  REP(i, N) {
    int t = 0;
    for (int j = i; j < N; j++) {
      if (j - i + 1 > 6) break;
      t = t * 10 + num[j];
      num_set.insert(t);
    }
  }

  REP(i, 1e6) {
    if (num_set.find(i) == num_set.end()) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
