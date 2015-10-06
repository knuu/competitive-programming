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

  int N, K;
  cin >> N >> K;

  priority_queue<P> old;
  REP(i, K) {
    int x;
    cin >> x;
    old.push(P(x, i+1));
  }

  cout << old.top().second << endl;

  FOR(i, K, N) {
    int x;
    cin >> x;
    if (x < old.top().first) {
      old.pop();
      old.push(P(x, i+1));
    }
    cout << old.top().second << endl;
  }

  return 0;
}
