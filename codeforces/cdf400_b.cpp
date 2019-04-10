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

struct Prime {
  vector<bool> sieve;
  vector<int> primes;
  Prime(int N) {
    assert(N >= 1);
    sieve.resize(N+1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= N; i++) {
      if (sieve[i]) {
        primes.push_back(i);
        for (int j = 2 * i; j <= N; j += i) sieve[j] = false;
      }
    }
  }
};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  if (N <= 2) {
    cout << 1 << endl;
    REP(i, N) cout << 1 << (i == N - 1 ? '\n' : ' ');
  } else {
    Prime ps(N + 1);
    cout << 2 << endl;
    REP(i, N) cout << (ps.sieve[i+2] ? 1 : 2) << (i == N - 1 ? '\n' : ' ');
  }

  return 0;
}
