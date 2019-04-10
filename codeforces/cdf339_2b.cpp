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
  string ans = "1";
  REP(i, N) {
    string a;
    cin >> a;
    if (a == "0") {
      cout << 0 << endl;
      return 0;
    } else {
      bool flag = true;
      REP(j, a.size()) flag &= a[j] == (j == 0 ? '1' : '0');
      if (flag) {
	ans += a.substr(1, a.size() - 1);
      } else {
	ans = a + ans.substr(1, ans.size() - 1);
      }
    }
    // cout << ans << endl;
  }
  cout << ans << endl;	
  return 0;
}
