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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  REP(i, T) {
    int N;
    cin >> N;
    Vi array;
    REP(j, N) {
      int n;
      cin >> n;
      auto it = upper_bound(array.begin(), array.end(), n);
      if (it == array.end()) {
	array.push_back(n);
      } else {
	array[it-array.begin()] = n;
      }
    }
    cout << array.size() << ' ';
    REP(i, array.size()) cout << array[i] << (i == (int)array.size()-1 ? '\n' : ' ');
  }    
  return 0;
}
