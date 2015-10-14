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

  int N, lessons[128];
  cin >> N;
  REP(i, N) cin >> lessons[i];
  int ans = 0;
  int i = 0;
  while (i < N && lessons[i] == 0) i++;

  while (i < N) {
    if (lessons[i] == 1) {
      ans++;
      i++;
    } else if (i < N-1 && lessons[i] == 0 && lessons[i+1] == 0) {
      i += 2;
      while (i < N && lessons[i] == 0) i++;
    } else if (i == N-1 && lessons[i] == 0) {
      i++;
    } else {
      ans++;
      i++;
    }
  }
  cout << ans << endl;
  return 0;
}
