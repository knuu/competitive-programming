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
  ll x; cin >> x;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> B = A;
  ll ans = 1e18, sum = accumulate(ALL(A), 0LL);
  REP(i, N) {
    REP(j, N) {
      if (A[(j+i)%N] < B[j]) {
        sum = sum - B[j] + A[(j+i)%N];
        B[j] = A[(j+i)%N];
      }
    }
    ans = min(ans, sum + (ll)i * x);
  }
  //REP(i, N) cout << A[i] << (i == N-1 ? '\n' : ' ');
  cout << ans << endl;
  return 0;
}
