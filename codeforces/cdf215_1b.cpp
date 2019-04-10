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
  ll N, M, P; cin >> N >> M >> P;
  vector<int> A(N), B(M);
  REP(i, N) scanf("%d", &A[i]);
  REP(i, M) scanf("%d", &B[i]);

  vector<int> ans;
  vector<bool> used(N, false);
  for (int q = 0; (ll)q + (M - 1) * P < N; q++) {
    if (used[q]) continue;
    used[q] = true;
    map<int, int> counter;
    for (int b : B) counter[b]++;
    REP(i, M) {
      counter[A[q+i*P]]--;
      if (not counter[A[q+i*P]]) counter.erase(A[q+i*P]);
    }
    if (counter.empty()) ans.push_back(q+1);

    for (int qq = q + P; qq + (M - 1) * P < N; qq += P) {
      used[qq] = true;
      counter[A[qq-P]]++;
      if (counter[A[qq-P]] == 0) counter.erase(A[qq-P]);
      counter[A[qq + (M - 1) * P]]--;
      if (counter[A[qq + (M - 1) * P]] == 0) counter.erase(A[qq + (M - 1) * P]);
      if (counter.empty()) ans.push_back(qq+1);
    }
  }
  sort(ALL(ans));
  printf("%d\n", (int)ans.size());
  REP(i, ans.size()) {
    if (i) printf(" ");
    printf("%d", ans[i]);
    if (i + 1 == (int)ans.size()) printf("\n");
  }
  return 0;
}
