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

  ll N, K; cin >> N >> K;
  vector<ll> divisors;
  for (ll i = 1; i <= (ll)(sqrt(N) + 1e-9); i++) {
    if (N % i == 0) {
      divisors.push_back(i);
      if (i * i != N) {
        divisors.push_back(N / i);
      }
    }
  }
  sort(ALL(divisors));
  cout << (K <= divisors.size() ? divisors[K-1] : -1) << endl;
  return 0;
}
