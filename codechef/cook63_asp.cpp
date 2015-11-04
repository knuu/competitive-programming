#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

int A[1000010];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  REP(t, T) {
    int N;
    cin >> N;
    REP(i, N) cin >> A[i];

    REP(i, N-1) {
      if (A[i] > A[i+1]) {
	swap(A[i], A[i+1]);
	i++;
      }
    }
    bool flag = true;
    REP(i, N-1) {
      if (A[i] > A[i+1]) {
	flag = false;
	break;
      }
    }
    cout << (flag ? "YES" : "NO") << endl;
  }
  return 0;
}
