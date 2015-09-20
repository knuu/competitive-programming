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

ll A[32];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll N, K;
  cin >> N >> K;
  REP(i, N) cin >> A[i];

  REP(i, 1<<N) {
    int sum = 0;
    REP(j, N) {
      if (i >> j & 1) sum += A[j];
    }
    if (sum == K) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
