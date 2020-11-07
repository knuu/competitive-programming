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

  int N; cin >> N;
  vector<int> A(3), B(3);
  REP(i, 3) cin >> A[i];
  REP(i, 3) cin >> B[i];

  vector<int> dp(N+1);
  REP(i, 3) {
    if (B[i] - A[i] <= 0) continue;
    REP(w, N+1) {
      if (w >= A[i]) {
        dp[w] = max(dp[w], dp[w-A[i]] + B[i] - A[i]);
      }
    }
  }

  int M = *max_element(ALL(dp)) + N;
  vector<ll> dp2(M+1);
  REP(i, 3) {
    if (A[i] - B[i] <= 0) continue;
    REP(w, M+1) {
      if (w >= B[i]) {
        dp2[w] = max(dp2[w], dp2[w-B[i]] + A[i] - B[i]);
      }
    }
  }

  cout << *max_element(ALL(dp2)) + M << endl;

  return 0;
}
