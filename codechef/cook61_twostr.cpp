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
  int T;
  cin >> T;
  REP(i, T) {
    string X, Y;
    cin >> X >> Y;
    bool flag = true;
    REP(j, X.length()) {
      if (X[j] != '?' && Y[j] != '?' && X[j] != Y[j]) {
	cout << "No" << endl;
	flag = false;
	break;	  
      }
    }
    if (flag) cout << "Yes" << endl;
  }
  return 0;
}
