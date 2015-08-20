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
  int N;
  int d[512];
  cin >> N;
  REP(i, N) cin >> d[i];

  int sum = accumulate(d, d+N, 0);

  cout << sum << endl;
  cout << max(0, 2 * d[max_element(d, d+N) - d] - sum) << endl;
  return 0;
}
