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

  int N; ll K; cin >> N >> K;
  assert(K != 0);
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> acc(N + 1, 0); REP(i, N) acc[i + 1] += acc[i] + A[i];
  map<ll, int> acc_count; REP(i, N + 1) acc_count[acc[i]]++;

  vector<ll> cand;
  if (K == 1) {
    cand.push_back(1);
  } else if (K == -1) {
    cand.push_back(1);
    cand.push_back(-1);
  } else {
    for (ll now = 1; abs(now) < (ll)1e18; now *= K) {
      cand.push_back(now);
    }
  }

  ll ans = 0;
  REP(i, N) {
    for (ll x : cand) {
      ans += acc_count[acc[i] + x];
    }
    acc_count[acc[i]]--;
  }
  cout << ans << endl;
  return 0;
}
