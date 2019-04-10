#include <bits/stdc++.h>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()

#define MAX_LOG_N 17

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<vector<int>> hotels(2, vector<int>(N));
  REP(i, N) cin >> hotels[0][i];
  REP(i, N) hotels[1][i] = hotels[0][N-1] - hotels[0][N-1-i];

  int L, Q; cin >> L >> Q;
  vector<int> A(Q), B(Q); REP(i, Q) cin >> A[i] >> B[i], A[i]--, B[i]--;

  // doubling
  vector<vector<vector<int>>> doubling(2, vector<vector<int>>(MAX_LOG_N, vector<int>(N)));
  REP(k, 2) REP(i, N) {
    doubling[k][0][i] = upper_bound(ALL(hotels[k]), hotels[k][i] + L) - hotels[k].begin() - 1;
  }
  REP(k, 2) REP(i, MAX_LOG_N-1) REP(j, N) {
    doubling[k][i+1][j] = doubling[k][i][doubling[k][i][j]];
  }

  REP(q, Q) {
    int k = A[q] > B[q], a = A[q], b = B[q];
    if (a > b) a = N-1 - a, b = N-1 - b;
    assert(a < b);

    int ans = 0;
    for (int i = MAX_LOG_N-1; i >= 0; i--) {
      if (doubling[k][i][a] < b) ans += 1 << i, a = doubling[k][i][a];
    }
    cout << ans+1 << endl;
  }

  return 0;
}
