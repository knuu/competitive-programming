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
  int N, ans[6];
  cin >> N;
  fill(ans, ans+6, 0);

  REP(i, N) {
    double MT, mt;
    cin >> MT >> mt;
    if (MT >= 35) ans[0]++;
    else if (MT >= 30) ans[1]++;
    else if (MT >= 25) ans[2]++;

    if (mt >= 25) ans[3]++;

    if (mt < 0 && MT >= 0) ans[4]++;
    else if (mt < 0) ans[5]++;
  }
  
  REP(i, 6) cout << ans[i] << (i == 5 ? '\n' : ' ');
  return 0;
}
