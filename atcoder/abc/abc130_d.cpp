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
  ll N, K; cin >> N >> K;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> acc(N+1); REP(i, N) acc[i+1] = acc[i] + A[i];
  //REP(i, N) cout << A[i] << (i == N-1 ? '\n' : ' ');
  //REP(i, N+1) cout << acc[i] << (i == N ? '\n' : ' ');

  ll ans = N * (N-1) / 2 + N;
  //cout << ans << endl;
  REP(i, N) {
    int left = i, right = N+1;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      if (acc[mid]-acc[i] < K) {
        left = mid;
      } else {
        right = mid;
      }
    }
    //cout << acc[left] - acc[i] << endl;
    //cout << left << ' ' << right << ' ' << endl;
    ll L = left - i;
    ans -= L;
  }
  cout << ans << endl;

  return 0;
}
