#include <bits/stdc++.h>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int main() {
  int N, K; cin >> N >> K;
  string S; cin >> S;

  vector<int> charsCount(26, 0);
  vector<vector<int>> charsCountImos(26, vector<int>(N+1, 0));

  REP(i, N) charsCount[S[i] - 'a']++, charsCountImos[S[i] - 'a'][i+1]++;
  REP(i, 26) REP(j, N) charsCountImos[i][j+1] += charsCountImos[i][j];

  string ans(N, -1);
  int now_cost = 0;

  REP(i, N) {
    REP(j, 26) {
      if (charsCount[j] > 0) {
        vector<int> cand_s(N, -1);
        int cand_c = (S[i] - 'a') != j;

        REP(k, 26) {
          cand_c += max(charsCount[k] - (j == k) - (charsCountImos[k][N] - charsCountImos[k][i+1]), 0);
        }
        if (now_cost + cand_c <= K) {
          ans[i] = j + 'a';
          charsCount[j]--;
          now_cost += (S[i] - 'a') != j;
          break;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
