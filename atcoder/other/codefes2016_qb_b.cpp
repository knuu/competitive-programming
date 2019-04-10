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

  int N, A, B; cin >> N >> A >> B;
  int sum = A + B;
  string S; cin >> S;
  for (char s : S) {
    if (s == 'a') {
      if (sum) {
        cout << "Yes" << endl;
        sum--;
      } else {
        cout << "No" << endl;
      }
    } else if (s == 'b') {
      if (B and sum) {
        cout << "Yes" << endl;
        B--;
        sum--;
      } else {
        cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
