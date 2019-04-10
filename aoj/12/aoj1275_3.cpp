#include <bits/stdc++.h>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  while (1) {
    int N, K, M; cin >> N >> K >> M;
    if (N == 0 and K == 0 and M == 0) break;
    M--;
    vector<int> stones(N); REP(i, N) stones[i] = i;
    while (stones.size() > 1) {
      stones.erase(stones.begin() + M);
      M = (M + K - 1 + stones.size()) % stones.size();
    }
    cout << stones[0] + 1 << endl;
  }
  return 0;
}
