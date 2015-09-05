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
  int N, C, odd[10], even[10];
  cin >> N >> C;
  fill(odd, odd + 10, 0);
  fill(even, even + 10, 0);

  REP(i, N) {
    int a;
    cin >> a;
    if (i % 2 == 0) {
      even[a-1]++;
    } else {
      odd[a-1]++;
    }
  }

  int ans = (N - even[0] - odd[1]) * C;
  REP(i, 10) {
    REP(j, 10) {
      if (i == j) continue;
      ans = min(ans, (N - even[i] - odd[j]) * C);
    }
  }

  cout << ans << endl;
  return 0;
}
