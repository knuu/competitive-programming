#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
//typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  int N; scanf("%d", &N);
  vector<int> P(N); REP(i, N) scanf("%d", &P[i]);
  vector<int> A(N); REP(i, N) scanf("%d", &A[i]), A[i]--;
  vector<int> B(N); REP(i, N) scanf("%d", &B[i]), B[i]--;

  priority_queue<pair<int, int>> pque[3];
  REP(i, N) {
    pque[A[i]].emplace(-P[i], i);
    if (A[i] != B[i]) pque[B[i]].emplace(-P[i], i);
  }

  int M; scanf("%d", &M);
  vector<int> ans(M);
  vector<bool> used(N, false);

  REP(i, M) {
    int c; scanf("%d", &c); c--;
    while (not pque[c].empty() and used[pque[c].top().second]) pque[c].pop();
    if (pque[c].empty()) {
      ans[i] = -1;
    } else {
      int p, idx; tie(p, idx) = pque[c].top(); pque[c].pop();
      ans[i] = -p;
      used[idx] = true;
    }
  }

  REP(i, M) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");

  return 0;
}
