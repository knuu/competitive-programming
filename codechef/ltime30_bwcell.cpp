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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  REP(_, T) {
    string cell;
    cin >> cell;
    int N = cell.size();
    bool flag = true;
    REP(i, N) if (cell[i] == 'W') flag = false;
    if (flag) {
      cout << "Chef" << endl;
      continue;
    }
    
    int b = 0;
    REP(i, N) {
      if (cell[i] == 'B') {
	int s = i;
	while (i < N && cell[i] == 'B') i++;
	b ^= i - s - (s != 0 && i != N);
      }
    }
    cout << (b ? "Aleksa" : "Chef") << endl;
  }  
  return 0;
}
