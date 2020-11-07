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
  int N = 20;
  int a[3] = {100, 100, 200};
  REP(i, N-1) {
    int tmp1 = a[1], tmp2 = a[2];
    a[2] += a[0] + a[1];
    a[1] = tmp2;
    a[0] = tmp1;
  }
  cout << a[0] << endl;
  return 0;
}
