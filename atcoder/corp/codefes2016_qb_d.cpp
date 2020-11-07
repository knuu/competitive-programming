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
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];

  ll ans = A[0]-1, lb = 2;
  FOR(i, 1, N) {
    if (A[i] < lb) {
      continue;
    } else if (A[i] == lb) {
      lb++;
    } else if (A[i] % lb == 0) {
      ans += A[i] / lb - 1LL;
    } else {
      ans += A[i] / lb;
    }
  }
  cout << ans << endl;
  return 0;
}
