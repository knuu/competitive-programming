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
  int N, M, T; cin >> N >> M >> T;
  vector<int> A(N); REP(i, N) cin >> A[i];
  int ans = 0;
  ans += A[0] - M;
  REP(i, N-1) {
    ans += max(0, A[i+1] - A[i] - 2 * M);
  }
  ans += max(0, T - A[N-1] - M);
  cout << ans << endl;
  return 0;
}
