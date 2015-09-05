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
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

int main() {
  string A;
  int ans = 0;

  cin >> A;

  int diff = 0, N = A.size();
  REP(i, N/2) {
    if (A[i] != A[N-i-1]) diff++;
  }

  REP(i, N) {
    REP(j, 26) {
      if (A[i] == 'A' + j) continue;
      if (diff - (A[i] != A[N-i-1] && A[N-i-1] == 'A' + j) + (i != N-i-1 && A[i] == A[N-i-1] && A[N-i-1] != 'A' + j) > 0) ans++;
    }
  }
			 
  cout << ans << endl;
  return 0;
}
