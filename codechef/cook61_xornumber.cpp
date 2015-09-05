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

vector<ll> ok;

int main() {

  for (int i = 3; i <= (1<<30); i = 2*i + 1) {
    ok.push_back(i);
  }
  
  int T;
  cin >> T;
  REP(i, T) {
    ll N;
    cin >> N;
    if (N == 1) {
      cout << 2 << endl;
    } else if (find(ALL(ok), N) != ok.end()) {
      assert (N == ((N / 2) ^ (N / 2 + 1)));
      cout << N / 2 << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
