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

int B[100010];

int main() {
  int L;
  cin >> L;
  REP(i, L) {
    int b;
    cin >> b;
    B[i+1] = b^B[i];
  }

  if (B[L] != B[0]) {
    cout << -1 << endl;
  } else {
    REP(i, L) cout << B[i] << endl;
  }
      
  return 0;
}
