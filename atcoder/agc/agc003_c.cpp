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
  map<int, int> even, odd, seven, sodd;
  set<int> S;
  vector<int> A(N);
  REP(i, N) {
    cin >> A[i];
    S.insert(A[i]);
    (i % 2 == 0 ? even : odd)[A[i]]++;
  }
  sort(ALL(A));
  REP(i, N) (i % 2 == 0 ? seven : sodd)[A[i]]++;

  int ecnt = 0, ocnt = 0;
  for (auto k : S) {
    //cout << k << ':' << even[k] << ',' << odd[k] << ',' << seven[k] << ',' << sodd[k] << endl;
    assert(even[k] + odd[k] == seven[k] + sodd[k]);
    if (even[k] > seven[k]) {
      ecnt += even[k] - seven[k];
    } else {
      assert(odd[k] >= sodd[k]);
      ocnt += odd[k] - sodd[k];
    }
  }
  //cout << ecnt << ' ' << ocnt << endl;
  assert(ecnt == ocnt);
  cout << ecnt << endl;
  return 0;
}
