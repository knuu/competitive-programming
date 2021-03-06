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

  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];

  ll ans = 0;
  REP(i, N) {
    if (A[i] > 0) {
      ans += A[i] / 2LL;
      if (A[i] % 2LL == 1LL and i < N-1 and A[i+1] > 0) ans++, A[i+1]--;
    }
    //cout << i << ' ' << ans << endl;
  }
  cout << ans << endl;

  return 0;
}
