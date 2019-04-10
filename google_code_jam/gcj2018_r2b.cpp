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
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  REP(testcase, T) {
    int S; cin >> S;
    vector<int> D(S), A(S), B(S);
    REP(i, S) cin >> D[i] >> A[i] >> B[i];
    vector<int> ans;
    REP(left, S) FOR(right, left, S) {
      set<int> AA;
      FOR(i, left, right + 1) {
        AA.insert(D[i] + A[i]);
      }
      bool flag = false;
      for (int x : AA) {
        vector<int> BB;
        FOR(i, left, right + 1) {
          if (D[i] + A[i] != x) {
            BB.emplace_back(D[i] - B[i]);
          }
        }
        if (BB.size() == 0 or all_of(ALL(BB), [&](int x) { return BB[0] == x; })) {
          flag = true;
          break;
        }
      }
      if (flag) {
        ans.emplace_back(right - left + 1);
      }
    }
    int ans_val = *max_element(ALL(ans));
    int cnt = count(ALL(ans), ans_val);
    cout << "Case #" << testcase + 1 << ": " << ans_val << ' ' << cnt << endl;
  }

  return 0;
}
