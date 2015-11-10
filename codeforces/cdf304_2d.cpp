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

int sieve[5000001];

int main() {
  int T;
  scanf("%d", &T);
  fill(sieve, sieve + 5000001, true);
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i <= (int)sqrt(5000000); i++) {
    if (sieve[i] == 1) {
      for (int j = 2 * i; j <= 5000001; j += i) {
	sieve[j] = i;
      }
    }
  }
  
  FOR(i, 2, 5000001) {
    if (sieve[i] == 1) {
      sieve[i] = 1;
    } else {
      sieve[i] = sieve[i/sieve[i]] + 1;
    }
  }
  FOR(i, 2, 5000000) sieve[i+1] += sieve[i];

  REP(t, T) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", sieve[a] - sieve[b]);
  }
  return 0;
}
