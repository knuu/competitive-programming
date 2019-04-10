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

  int T; cin >> T;
  REP(_, T) {
    int N; cin >> N;
    vector<ll> A(N); REP(i, N) cin >> A[i];
    vector<ll> S(N, -1e15), E(N, -1e15);
    E[0] = A[0];
    REP(i, N-1) E[i+1] = max(A[i+1], E[i] + A[i+1]);
    S[N-1] = A[N-1];
    for (int i = N-2; i >= 0; i--) S[i] = max(A[i], S[i+1] + A[i]);

    ll ans = *max_element(ALL(E));
    FOR(i, 1, N-1) ans = max(ans, E[i-1] + S[i+1]);
    cout << ans << endl;
  }
  return 0;
}
