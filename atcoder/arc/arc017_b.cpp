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
  int N, K, ans = 0, suc = 0, prev = 0;
  cin >> N >> K;
  
  REP(i, N) {
    int a;
    cin >> a;
    if (a > prev) {
      suc++;
    } else {
      suc = 1;
    }
    prev = a;

    if (suc >= K) ans++;
  }

  cout << ans << endl;
  return 0;
}
