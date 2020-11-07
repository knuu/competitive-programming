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

  int N, L; cin >> N >> L;
  vector<int> A(N); REP(i, N) cin >> A[i];

  REP(i, N-1) {
    if (A[i] + A[i+1] >= L) {
      cout << "Possible" << endl;
      REP(j, i) {
        cout << j+1 << endl;
      }
      for (int j = N-1; j > i+1; j--) {
        cout << j << endl;
      }
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << "Impossible" << endl;

  return 0;
}