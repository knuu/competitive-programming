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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll N;
  cin >> N;
  int depth = 0;
  for (ll i = N; i > 0; i/=2) depth++;

  int turn = 0;
  ll x = 1;
  while (x <= N) {
    x = (x << 1) + (turn ^ (depth & 1));
    turn ^= 1;
  }

  cout << (turn ? "Aoki" : "Takahashi") << endl;

  return 0;
}
